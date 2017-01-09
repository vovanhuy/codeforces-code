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
	int n, k; cin >> n >> k;
	int t[n];
	
	rep(i, 0, n){
		cin >> t[i];
		if(t[i] < 0) t[i] = -1;
		else t[i] = 1;
	}

	vi neg, pos;
	int count = 0, sign = -1;
	int begin_pos = - 1;
	rep(i, 0, n){
		if(t[i] == -1){
			begin_pos = i;
			break;
		}
	}
	if(begin_pos == -1){
		cout << 0 << endl;
		return 0;
	}

	rep(i, begin_pos, n){
		if(t[i] == sign) count++;
		else{
			if(sign == 1) pos.pb(count);
			else neg.pb(count);
			count = 1;
			sign = t[i];
		}
	}
	if(sign == 1) pos.pb(count);
	else neg.pb(count);

	int sum_neg = 0;
	rep(i, 0, neg.size()) sum_neg += neg[i];
	if(sum_neg > k){
		cout << -1 << endl;
		return 0;
	}
	if(pos.size() == 0){
		cout << 1 << endl;
		return 0;
	}

	k -= sum_neg;
	int val[pos.size()];
	rep(i, 0, pos.size()){
		val[i] = 2;
	}

	if(t[n-1] == 1) val[pos.size() - 1] = 1;
	int sum_change = 0;
	rep(i, 0, pos.size()) sum_change += val[i];

	if(val[pos.size() - 1] == 1){

		sort(pos.begin(), pos.end()-1);

		int res1 = 0;
		int temp = k;
		rep(i, 0, pos.size() - 1){
			if(temp >= pos[i]){
				temp -= pos[i];
				res1 += 2;
			}
		}

		int res2 = 0;
		temp = k >= pos[pos.size() - 1]? k - pos[pos.size()-1] : k;
		if(temp < k) res2++;
		rep(i, 0, pos.size() - 1){
			if(temp >= pos[i]){
				temp -= pos[i];
				res2 += 2;
			}
		}

		cout << sum_change - max(res1, res2) + 1 << endl;
	}
	else{
		sort(pos.begin(), pos.end());
		int res1 = 0;
		int temp = k;
		rep(i, 0, pos.size()){
			if(temp >= pos[i]){
				temp -= pos[i];
				res1 += 2;
			}
		}

		cout << sum_change + 1 - res1 << endl;
	}

	// print_vector(pos);
	// print_vector(neg);

	

	return 0;
}