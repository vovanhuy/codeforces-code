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
#include <string>

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

string create_palindrome(string s){
	vector<char> v(s.length());
	rep(i, 0, s.length()){
		v[s.length() - i  - 1] = s[i];
	}
	return string(v.begin(), v.end());
}

bool is_palindrome(string s){
	rep(i, 0, s.length()){
		if(s[i] != s[s.length() - i - 1]) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k, n; cin >> k >> n;
	map<string, vector<ll> > m;
	rep(i, 0, k){
		string s; 
		ll a;
		cin >> s >> a;
		m[s].pb(a);
	}

	ll res1 = 0, res2 = 0;
	vector<pll> mark;

	for(auto el:m){
		if(!is_palindrome(el.fi)){
			vector<ll> h = el.sn;
			vector<ll> t = m[create_palindrome(el.fi)];
			sort(h.begin(), h.end(), greater<int>());
			sort(t.begin(), t.end(), greater<int>());
			int len = min(h.size(), t.size());

			rep(i, 0, len){
				if(h[i] + t[i] > 0){
					res1 += h[i] + t[i];
				}
				else break;
			}
		}
		else{
			int len = el.sn.size();
			sort(el.sn.begin(), el.sn.end(), greater<int>());
			pll mark_local = pll(0, 0);
			rep(i, 0, len/2){
				if(el.sn[2*i] > 0 && el.sn[2*i + 1] > 0){
					res2 += el.sn[2*i] + el.sn[2*i + 1];
				}
				else{
					if(el.sn[2*i] + el.sn[2*i+1] > 0) mark_local.fi = el.sn[2*i] + el.sn[2*i+1];
					if(el.sn[2*i] > 0) mark_local.sn = el.sn[2*i];
					break;
				}
			}
			if(len % 2 == 1 && el.sn[len - 1] > 0){
				mark_local.fi = 0;
				mark_local.sn = el.sn[len - 1];
			}

			mark.pb(mark_local);
		}
	}

	ll res = 0;
	ll max_gain = 0;
	rep(i, 0, mark.size()){
		max_gain = max(max_gain, mark[i].sn - mark[i].fi);
		res += mark[i].fi;
	}
	res += max_gain;
	cout << res1/2 + res2 + res << endl;

	return 0;
}