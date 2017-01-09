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
	ll c; cin >> c;
	ll p[n+1], s[n+1];
	rep(i, 1, n+1) cin >> p[i];
	rep(i, 1, n+1) cin >> s[i];

	ll partial_p[n+1], partial_s[n+1];
	partial_s[0] = partial_p[0] = 0;
	rep(i, 1, n+1){
		partial_p[i] = partial_p[i-1] + p[i];
		partial_s[i] = partial_s[i-1] + s[i];
	}

	ll odd[n+1], even[n+1];
	ll *current, *past;

	odd[0] = partial_p[n];
	odd[1] = s[1] + partial_p[n] - partial_p[1] + c*(n-1);

	rep(i, 2, n + 1){
		if(i & 1){
			current = odd;
			past = even;
		}
		else{
			current = even;
			past = odd;
		}

		current[0] = partial_p[n];
		rep(j, 1, i){
			current[j] = min(past[j-1] + s[i] + (n-j)*c - p[i] - (j-1)*c, past[j]); 
		}
		current[i] = partial_s[i] + partial_p[n] - partial_p[i] + i * (n-i) * c;

		// print_array(odd, n + 1);
		// print_array(even, n+1);
	}

	ll result = numeric_limits<ll>::max();
	if(n & 1) current = odd;
	else current = even;
	rep(i, 0, n+1){
		result = min(result, current[i]);
	}

	cout << result << endl;


	return 0;
}