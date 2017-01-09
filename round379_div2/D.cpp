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
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int num; cin >> num;
	int x, y; cin >> x >> y;
	int n = MAXINT, e = MAXINT, s = MININT, w = MININT;
	int ne = MAXINT, nw = MININT, se = MAXINT, sw = MININT;
	char char_n = 'H', char_e = 'H', char_w = 'H', char_s = 'H';
	char char_ne= 'H', char_nw = 'H', char_se = 'H', char_sw = 'H';
	rep(i, 0, num){
		char c; cin >> c;
		int a, b; cin >> a >> b;
		if(a == x){
			if(b < y){
				if(b > s){
					s = b;
					char_s = c;
				}
			}
			else{
				if(b > y){
					if(b < n){
						n = b;
						char_n = c;
					}
				}
			}
		}
		if(b == y){
			if(a < x){
				if(a > w){
					w = a;
					char_w = c;
				}
			}
			else{
				if(a < e){
					e = a;
					char_e = c;
				}
			}
		}

		if(a + b == x + y){
			if(a < x){
				if(a > nw){
					nw = a;
					char_nw = c;
				}
			}
			else{
				if(a < se){
					se = a;
					char_se = c;
				}
			}
		}
		if(a - b == x - y){
			if(a < x){
				if(a > sw){
					sw = a;
					char_sw = c;
				}
			}
			else{
				if(a < ne){
					ne = a;
					char_ne = c;
				}
			}
		}
	}

	if(char_n == 'R' || char_n == 'Q' || char_s == 'R' || char_s == 'Q' ||
		char_w == 'R' || char_w == 'Q' || char_e == 'R' || char_e == 'Q' ||
		char_ne == 'Q' || char_ne == 'B' || char_nw == 'Q' || char_nw == 'B' ||
		char_sw == 'Q' || char_sw == 'B' || char_se == 'Q' || char_se == 'B'){
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

	return 0;
}