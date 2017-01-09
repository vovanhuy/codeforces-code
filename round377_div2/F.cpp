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
const int MAX_NODE = 400005;
list<int> edge[MAX_NODE];
int n, m;
int next_component;
stack<int> st;

struct Node
{
	int component;
	int low_link;
	int on_stack;
}tarjan[MAX_NODE];


void strong_connect(int v, int index){
	tarjan[v].component = index;
	tarjan[v].low_link = index;
	st.push(v);
	tarjan[v].on_stack = true;

	for(list<int>::iterator it = edge[v].begin(); it != edge[v].end(); it++){
		if(tarjan[*it].on_stack == false){
			strong_connect(*it, index+1);
			tarjan[v].low_link = min(tarjan[v].low_link, tarjan[*it].low_link);
		}
		else{
			tarjan[v].low_link = min(tarjan[v].low_link, tarjan[*it].component);
		}
	}

	// if v is a root
	if(tarjan[v].low_link == tarjan[v].component){
		int w;
		do{
			w = st.top(); st.pop();
			tarjan[w].component = next_component;
		}while(w != v);
		next_component++;
	}
}

list<int> graph[400005];

void construct_directed_graph(){
	int parent[n];
	bool visited[n];
	memset_array(visited, false, n);
	memset_array(parent, -1, n);
	stack<int> dfs;
	dfs.push(0);
	parent[0] = 0;
	while(!dfs.empty()){
		int current = dfs.top(); dfs.pop();
		if(!visited[current]){
			if(current != 0) edge[parent[current]].pb(current);
			for(li::iterator it = graph[current].begin(); it != graph[current].end(); it++){
				if(!visited[*it]){
					parent[*it] = current;
					dfs.push(*it);
				}
				else if(parent[current] != *it){
					edge[current].pb(*it);
				}
			}
			visited[current] = true;
		}
	}
}

void print_new_graph(){
	rep(i, 0, n){
		for(li::iterator it = edge[i].begin(); it != edge[i].end(); it++){
			cout << *it << " ";
		}
		cout << endl;
	}
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	rep(i, 0, n){
		edge[i].clear();
		tarjan[i].component = -1;
		tarjan[i].low_link = -1;
		tarjan[i].on_stack = false;
	}
	st = stack<int>();
	next_component = 0;
	vector<pii> edge_input;

	rep(i, 0, m){
		int x, y; cin >> x >> y;
		edge_input.pb(make_pair(x, y));
		graph[x-1].pb(y-1);
		graph[y-1].pb(x-1);
	}
	construct_directed_graph();
	// print_new_graph();
	rep(i, 0, n){
		if(tarjan[i].component == -1){
			// cout << "consider " << i << endl;
			strong_connect(i, 0);
		}
	}

	// cout << next_component << endl;
	int count[next_component];
	memset_array(count, 0, next_component);
	rep(i, 0 ,n){
		count[tarjan[i].component]++;
	}

	int result = 0;
	int max_component;
	rep(i, 0, next_component){
		if(count[i] > result){
			result = count[i];
			max_component = i;
		}
	}
	cout << result << endl;

	set<pii> final_result;

	bool visited[n];
	memset_array(visited, false, n);
	rep(i, 0, n){
		if(tarjan[i].component == max_component){
			for(li::iterator it = edge[i].begin(); it != edge[i].end(); it++){
				if(tarjan[*it].component == max_component){
					// cout << i+1 << " " << *it+1 << endl;
					final_result.insert(make_pair(i+1, *it+1));
				}
			}
		}
	}
	rep(i, 0, n){
		if(tarjan[i].component == max_component){
			visited[i] = true;
			// cout << "i: " << i+1 << endl;
		}
	}
	rep(i, 0, n){
		if(tarjan[i].component == max_component){
			// cout << "i here: " << i+1 << endl;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int current = q.front(); q.pop();
				visited[current] = true;
				for(li::iterator it = graph[current].begin(); 
						it != graph[current].end(); it++){
					if(!visited[*it]){
						// cout << *it+1 << " " << current+1 << endl;
						final_result.insert(make_pair(*it+1, current+1));
						// visited[*it] = true;
						q.push(*it);
					}
				}
			}
		}
	}

	rep(i, 0, edge_input.size()){
		if(final_result.find(edge_input[i]) != final_result.end()){
			cout << edge_input[i].fi << " " << edge_input[i].sn << endl;
		}
		else cout << edge_input[i].sn << " " << edge_input[i].fi << endl;
	}



	
	return 0;
}