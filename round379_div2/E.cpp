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
list<int> nb[200005]; //real graph
int color[200005];
list<int> nb_component[200005]; //graph of components
int n;
int dist[200005];
void build_np_component(){
	int component[n]; memset_array(component, -1, n);
	int next_compo = 0;
	rep(i, 0, n){
		if(component[i] == -1){
			queue<int> q; q.push(i); component[i] = next_compo++;
			while(!q.empty()){
				int cur = q.front(); q.pop();
				for(auto nei : nb[cur]){
					if(component[nei] == -1 && color[nei] == color[cur]){
						component[nei] = component[cur];
						q.push(nei);
					}
				}
			}
		}
	}
	rep(i, 0, n){
		for(auto nei : nb[i]){
			if(component[nei] != component[i]){
				nb_component[component[i]].pb(component[nei]);
			}
		}
	}
}

void bfs(int l){
	memset_array(dist, -1, n);
	dist[l] = 0;
	queue<int> q; q.push(l); dist[l] = 0;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(auto nei : nb_component[cur]){
			if(dist[nei] == -1){
				dist[nei] = dist[cur] + 1;
				q.push(nei);
			}
		}
	}
}

int find_longest_path(){
	bfs(0);
	int argmax, max_val = 0;
	rep(i, 0, n){
		if(dist[i] > max_val){
			max_val = dist[i];
			argmax = i;
		}
	}
	bfs(argmax);
	max_val = 0;
	rep(i, 0, n){
		if(dist[i] > max_val){
			max_val = dist[i];
			argmax = i;
		}
	}
	return (max_val+1)/2;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> color[i];
	rep(i, 0, n-1){
		int u, v; cin >> u >> v;
		nb[u-1].pb(v-1);
		nb[v-1].pb(u-1);
	}
	if(n == 1) cout << 0 << endl;
	else{
		build_np_component();
		cout << find_longest_path() << endl;
	}
	return 0;
}