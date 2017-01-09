// #include <bits/stdc++.h>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <sstream>

using namespace std;

#define MAXINT numeric_limits<int>::max()
#define MININT numeric_limits<int>::min()
#define PI 3.1415926
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define per(i, a, n) for(int i = (n)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define fi first
#define sn second
#define vi vector<int>
#define si set<int>
#define li list<int>
#define lit list<int>::iterator
#define sit set<int>::iterator
#define mit map<int, int>::iterator

	

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

template <typename T>
void print_array(T arr[], int size_arr){
	rep(i, 0, size_arr){
		cout << arr[i];
		if(i == size_arr - 1) cout << endl;
		else cout << " ";
	}
}

template<typename T>
void print_vector(vector<T> v){
	rep(i, 0, v.size()){
		cout << v[i];
		if(i == v.size() - 1) cout << endl;
		else cout << " ";
	}
}

template <typename T>
void memset_array(T arr[], T value, int size_arr){
	rep(i, 0, size_arr){
		arr[i] = value;
	}
}

bool compare_lexical_string(string a, string b){
	rep(i, 0, min(a.length(), b.length())){
		if(a[i] != b[i]) return a[i] < b[i];
	}
	return a.length() < b.length();
}
struct lex_string
{
	bool operator()(string a, string b){
		return compare_lexical_string(a, b);
	}
};



/////////////////////////////////////////////////////////////////////////////
// NEVER USE NAME : DISTANCE FOR FUNCTION
// NEVER USE NAME : FIND FOR FUNCTION
// AVOID DOUBLE IF POSSIBLE
////////////////////////////////////////////////////////////////////////////
// compare_lexical_string("huy", "huy") will return false
int dice[6] ={4, 6, 8, 10, 12, 20};
const int M=400;
map<int, int> my_map;
double dp[6][21][M+1];

void init(){
	my_map[4] = 0;
	my_map[6] = 1;
	my_map[8] = 2;
	my_map[10] = 3;
	my_map[12] = 4;
	my_map[20] = 5;

	rep(d, 0, 6){
		rep(h, 0, M+1){
			dp[d][0][h] = 0.0;
		}
		dp[d][0][0] = 1.0;
	}
}

void compute(){
	rep(d, 0, 6){
		rep(x, 1, 21){
			rep(h, 0, M+1){
				double sum = 0.0;
				rep(run, 1, dice[d]+1){
					if(h - run >= 0) sum += dp[d][x-1][h-run];
				}
				dp[d][x][h] = sum/(double)dice[d];
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	compute();
	// rep(i, 2, 9)
	// cout << dp[my_map[4]][2][i] << endl;
	int t; cin >> t;
	rep(test, 1, t+1){
		int h, s; cin >> h >> s;
		double cur_max = 0.0;
		rep(i, 0, s){
			string line;
			cin >> line;
			// cout << line << endl;
			int x, y, z;
			int found1 = line.find("d");
			string x_string = line.substr(0, found1);
			stringstream ssx(x_string);
			ssx >> x;
			int found2 = line.find("-");
			int sign = -1;
			if(found2 == string::npos){
				found2 = line.find("+");
				sign = 1;
			}

			if(found2 == string::npos){
				stringstream ssy(line.substr(found1+1, line.size() - found1 - 1));
				ssy >> y; 
				z= 0;
			}
			else{
				stringstream ssy(line.substr(found1+1, found2 - found1));
				ssy >> y; 
				stringstream ssz(line.substr(found2+1, line.size() -found2-1));
				ssz >> z;
				z = z * sign;
			}
			// cout << x << " " << y << " " << z << endl;
			int bound = max(0, h - z);

			double proba = 0.0;
			rep(val, bound, x*y+1){
				proba += dp[my_map[y]][x][val];
			}
			if(proba > cur_max) cur_max = proba;
			// cout << proba << endl;
		}
		cout << "Case #" << test << ": " << fixed << setprecision(8) << cur_max << endl;
	}
	return 0;
}