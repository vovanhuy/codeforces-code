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
vector<string> v;
vector< pair<string, int> > res;
int begin_pos = 0;

void dfs(int current_level){
	res.pb(make_pair(v[begin_pos++], current_level+1));
	stringstream ss(v[begin_pos++]);
	int child; ss >> child;
	rep(i, 0, child){
		dfs(current_level+1);
	}
}

void solve(){
	while(begin_pos < v.size()) dfs(0);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int begin_pos = 0;
	while(true){
		int pos = s.find(",", begin_pos);
		if(pos == -1){
			v.pb(s.substr(begin_pos, s.length() - begin_pos));
			break;
		}
		else{
			v.pb(s.substr(begin_pos, pos - begin_pos));
			begin_pos = pos + 1;
		}
	}
	solve();
	int max_depth = 0;
	rep(i, 0, res.size()){
		max_depth = max(max_depth, res[i].sn);
	}
	cout << max_depth << endl;
	vector<vector<string> > grid(max_depth);
	rep(i, 0, res.size()){
		grid[res[i].sn-1].pb(res[i].fi);
	}

	rep(i, 0, max_depth){
		print_vector(grid[i]);
	}

	return 0;
}