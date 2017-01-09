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
const int num = 302*302;
int x[8], y[8];

void init(){
	x[0] = x[4] = 0;
	x[1] = x[2] = x[3] = 1;
	x[5] = x[6] = x[7] = -1;

	y[2] = y[6] = 0;
	y[7] = y[0] = y[1] = 1;
	y[3] = y[4] = y[5] = -1;
}

bool dp[30][num][8];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	int n; cin >> n;
	int t[n];
	rep(i, 0, n) cin >> t[i];
	rep(i, 0, num){
		rep(j, 0, 8) dp[0][i][j] = false;
	}
	
	dp[0][150*302 + 150 + t[0]][0] = true;

	rep(i, 1, n){
		rep(cell, 0, num){
			int a = cell/302;
			int b = cell%302;
			rep(dir, 0, 8){
				int prev = (a - t[i] * x[dir]) * 302 + b - t[i]*y[dir];
				int first_dir = (dir+1)%8;
				int second_dir = (dir+7)%8;

				if(prev >= 0 && prev < num)
					if(dp[i-1][prev][first_dir] || dp[i-1][prev][second_dir]) dp[i][cell][dir] = true;
			}
		}
	}

	int count = 0;
	bool ans[num];
	memset_array(ans, false, num);
	rep(i, 0, n){
		rep(cell, 0, num){
			int a = cell/302;
			int b = cell%302;
			rep(dir, 0, 8){
				if(dp[i][cell][dir])
				rep(j, 0, t[i]){
					int prev = (a-j*x[dir])*302 + b-j*y[dir];
					if(prev >= 0 && prev < num) ans[prev] = true;
				}
			}
			
		}
	}

	rep(i, 0, num) if(ans[i]){
		// cout << i/302 << " " << i%302 << endl;
		count++;
	}
	cout << count << endl;
	return 0;
}