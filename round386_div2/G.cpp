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
	int n, t, k; cin >> n >> t >> k;
	int a[t+1];
	int dis[n+1];
	memset_array(dis, -1, n+1);
	dis[1] = 0;
	int one = 0;
	a[0] = 1;
	rep(i, 1, t+1){
		cin >> a[i];
	}
	rep(i, 0, t){
		if(a[i] > a[i + 1]){
			one += a[i] - a[i+1];
		}
	}
	if(one + a[t] > k){
		cout << -1 << endl;
		return 0;
	}


	multiset<int> s;
	int temp = k - a[t];
	per(i, 0, t){
		while(a[i] > a[i+1] && temp > 0){
			a[i]--;
			temp--;
			s.insert(i);
		}
	}
	// cout << s.size() << endl;

	cout << n << endl;
	int pos = 2;
	int root = 1;
	rep(i, 1, t+1){
		rep(j, 0, a[i]){
			cout << root << " " << pos << endl;
			dis[pos] = i;
			pos++;
			if(dis[root+1] == i - 1) root++;
		}
		root++;
	}

	root = 1;
	for(multiset<int>::iterator it = s.begin(); it != s.end(); it++){
		// cout << "here " << *it << " " << root << endl;
		while(dis[root] != *it - 1){
			root++;
		}
		cout << root << " " << pos << endl;
		pos++;
	}


	return 0;
}