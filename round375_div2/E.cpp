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
const int MAXNODE = 205;
multiset<int> adj[MAXNODE];
int deg[MAXNODE];

vector<int> path;
bool visited[MAXNODE];


void find_cycle(int begin_node){
	// use this function when it is already verified that there is
	// no odd degree node in the graph
	stack<int> st;
	st.push(begin_node);

	while(!st.empty()){
		int current = st.top();
		visited[current] = true;
		if(deg[current] == 0){
			st.pop(); path.pb(current);
		}
		else{
			int added = *adj[current].begin();
			st.push(added);
			adj[added].erase(adj[added].find(current));
			adj[current].erase(adj[current].begin());
			deg[added]--;
			deg[current]--;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		memset_array(deg, 0, MAXNODE);
		rep(i, 0, MAXNODE) adj[i].clear();
		path.clear();
		memset_array(visited, false, MAXNODE);

		int n, m; cin >> n >> m;
		rep(i, 0, m){
			int u, v; cin >> u >> v;
			adj[u-1].insert(v-1);
			adj[v-1].insert(u-1);
			deg[u-1]++;
			deg[v-1]++;
		}

		vi odd_node;
		rep(i, 0, n){
			if(deg[i] & 1) odd_node.pb(i);
		}

		set<pii> added_edges;
		rep(i, 0, odd_node.size()){
			adj[odd_node[i]].insert(odd_node[i+1]);
			adj[odd_node[i+1]].insert(odd_node[i]);
			deg[odd_node[i]]++;
			deg[odd_node[i+1]]++;
			added_edges.insert(pii(odd_node[i], odd_node[i+1]));
			added_edges.insert(pii(odd_node[i+1], odd_node[i]));
			i++;
		}

		cout << n - odd_node.size() << endl;

		// find cycle for each connected component
		rep(i, 0, n){
			if(!visited[i] && deg[i] != 0){
				path.clear();

				find_cycle(i);
				rep(j, 0, path.size() - 1){
					if(added_edges.find(pii(path[j], path[j+1])) == added_edges.end()){
						cout << path[j] + 1 << " " << path[j+1] + 1 << endl;
					}
					else{
						added_edges.erase(pii(path[j], path[j+1]));
						added_edges.erase(pii(path[j+1], path[j]));
					}
				}
			}
		}

	}
	
	return 0;
}