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
	string s; cin >> s;
	int a, b, c, d;
	a=b=c=d=0;
	rep(i, 0, n){
		if(s[i] == 'A') a++;
		if(s[i] == 'C') b++;
		if(s[i] == 'G') c++;
		if(s[i] == 'T') d++;
	}

	if(n%4 != 0 || a > n/4 || b > n/4 || c > n/4 || d > n/4){
		cout << "===" << endl;
		return 0;
	}

	rep(i, 0, n){
		if(s[i] == '?'){
			if(a < n/4){
				s[i] = 'A';
				a++;
			}
			else if(b < n/4){
			 	s[i] = 'C';
			 	b++;
			 }
			else if(c < n/4){
				s[i] ='G';
				c++;
			}
			else{
				 s[i] ='T';
				 d++;
			}
		}
	}
	cout << s << endl;
	return 0;
}