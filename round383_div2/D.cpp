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
	int n, m, W; cin >> n >> m >> W;
	int w[n];
	rep(i, 0, n) cin >> w[i];
	int b[n];
	rep(i, 0, n) cin >> b[i];

	list<int> g[n];
	rep(i, 0, m){
		int x, y; cin >> x >> y;
		g[x-1].pb(y-1);
		g[y-1].pb(x-1);
	}

	int compo[n];
	int num_compo = 0;
	memset_array(compo, -1, n);
	rep(i, 0, n){
		if(compo[i] == -1){
			compo[i] = num_compo++;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int cur = q.front(); q.pop();
				for(li::iterator it = g[cur].begin(); it != g[cur].end(); it++){
					if(compo[*it] == -1){
						compo[*it] = compo[cur];
						q.push(*it);
					}
				}
			}
		}
	}

	vector< vector<int> > C(num_compo+1);
	rep(i, 0, n){
		C[compo[i]+1].pb(i);
	}
	// cout << num_compo << endl;
	// rep(i, 0, num_compo){
	// 	print_vector(C[i]);
	// }

	ll sum_w[num_compo+1], sum_b[num_compo+1];
	rep(i, 1, num_compo+1){
		sum_w[i] = sum_b[i] = 0;
		rep(j, 0, C[i].size()){
			sum_w[i] += w[C[i][j]];
			sum_b[i] += b[C[i][j]];
		}
	}

	ll dp[num_compo+1][W+1];
	rep(i, 0, W+1){
		dp[0][i] = 0;
	}
	rep(i, 1, num_compo+1){
		// cout << "i" << i << endl;
		rep(j, 0, W+1){
			// cout << "j" << j << endl;
			dp[i][j] = dp[i-1][j];
			if(j >= sum_w[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-sum_w[i]] + sum_b[i]);
			rep(k, 0, C[i].size()){
				// cout << "k" << k << endl;
				if(j >= w[C[i][k]]) dp[i][j] = max(dp[i][j], dp[i-1][j-w[C[i][k]]] + b[C[i][k]]);
			}
		}
	}

	cout << dp[num_compo][W] << endl;

	
	return 0;
}