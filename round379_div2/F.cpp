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
	int n; cin >> n;
	ll b[n], c[n];
	rep(i, 0, n) cin >> b[i];
	rep(i, 0, n) cin >> c[i];
	ll sum_val = 0;
	rep(i, 0, n) sum_val += (b[i] + c[i]);
	if(sum_val % (2 * n) != 0){
		cout << -1 << endl;
		return 0;
	}
	else{
		ll sum_a = sum_val/(2*n);
		ll a[n];
		rep(i, 0, n){
			if((b[i] + c[i] - sum_a) % n != 0){
				cout << -1 << endl;
				return 0;
			}
			else a[i] = (b[i] + c[i] - sum_a) / n;
		}
		ll mark[n][32];
		ll part_sum[32]; memset_array(part_sum, (ll)0, 32);
		rep(i, 0, n){
			int temp = a[i];
			rep(j, 0, 32){
				mark[i][j] = temp % 2;
				part_sum[j] += mark[i][j];
				temp /= 2;
			}
		}
		// check c
		rep(i, 0, n){
			ll res = 0;
			ll power = 1;
			rep(j, 0, 32){
				if(mark[i][j] == 1) res += power * n;
				else res += power * part_sum[j];
				power *= 2;
			}
			if(res != c[i]){
				cout << -1 << endl;
				return 0;
			}
		}

		// check b
		rep(i, 0, n){
			ll res = 0;
			ll power = 1;
			rep(j, 0, 32){
				if(mark[i][j] == 1) res += power * part_sum[j];
				power *= 2;
			}
			if(res != b[i]){
				cout << -1 << endl;
				return 0;
			}
		}
		print_array(a, n);
	}
	return 0;
}