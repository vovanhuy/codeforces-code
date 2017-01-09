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
////////////////////////////////////////////////////////////////////////////
// compare_lexical_string("huy", "huy") will return false
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int a[n];
	rep(i, 0, n) cin >> a[i];
	int k; cin >> k;
	int b[k];
	rep(i, 0, k) cin >> b[i];
	vector< list<int> > v;
	int first = 0, second = 0;
	int cur_sum = 0;
	while(first < n){
		// cout << "here" << endl;
		if(cur_sum == 0) v.pb(li());

		cur_sum += a[first];
		v[second].pb(a[first]);
		if(cur_sum == b[second]){
			cur_sum = 0;
			second++;
		}
		if(cur_sum > b[second]){
			cout << "NO" << endl;
			return 0;
		}
		first++;
	}
	if(cur_sum != 0 || second != k){
		cout << "NO" << endl;
		return 0;
	}
	// cout << "huy" << endl;

	// cout << "YES" << endl;
	string res = "";

	rep(i, 0, second){
		// cout << "here";
		while(v[i].size() > 1){
			// cout << "here";
			// find_max
			int cur_max = 0;
			int cur_min = MAXINT;
			for(li::iterator it = v[i].begin(); it != v[i].end(); it++){
				cur_max = max(*it, cur_max);
				cur_min = min(cur_min, *it);
			}
			if(cur_max == cur_min){
				cout << "NO" << endl;
				return 0;
			}
			li::iterator it2 = v[i].begin();
			li::iterator it1 = v[i].begin();
			it2++;
			rep(j, 0, v[i].size() - 1){
				if(*it1 == cur_max && *it2 != cur_max){
					res = res + to_string(i+1 + j) + " R\n";
					*it1 = *it1 + *it2;
					v[i].erase(it2);
					break;
				}
				if(*it1 != cur_max && *it2 == cur_max){
					res = res + to_string(i+1 + j+1) + " L\n";
					*it2 = *it2 + *it1;
					v[i].erase(it1);
					break;
				}
				it1++;
				it2++;
			}

		}
	}
	cout << "YES" << endl;
	cout << res;
	
	return 0;
}