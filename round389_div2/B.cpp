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
	string s, t;
	cin >> s >> t;
	map<char, char> m;
	rep(i, 0, 26){
		m[(char)(i+'a')] = '?';
	}
	rep(i, 0, s.length()){
		if(m[s[i]] == '?'){
			m[s[i]] = t[i];
			if(m[t[i]] == '?') m[t[i]] = s[i];
			else if(m[t[i]] != s[i]){
				cout << -1 << endl;
				return 0;
			}
		}
		else if(m[s[i]] != t[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	int count = 0;
	rep(i, 0, 26){
		if(m[(char)(i+'a')] != '?' && m[(char)(i+'a')] != (char)(i+'a')) count += 1;
	}
	cout << count/2 << endl;
	rep(i, 0, 26){
		if(m[(char)(i+'a')] != '?' && m[(char)(i+'a')] != (char)(i+'a')){
			cout << (char)(i + 'a') << " " <<m[(char)(i+'a')] << endl;
			m[m[(char)(i+'a')]] = '?';
			m[(char)(i+'a')] = '?';
		}
	}
	return 0;
}