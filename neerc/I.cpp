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
// compare_lexical_string("huy", "huy") will return false
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, p, s; cin >> n >> p >> s;
	int a[n], b[n];
	rep(i, 0, n){
		cin >> a[i];
	}
	rep(i, 0, n) cin >> b[i];

	list<int> neighbor[n+4];
	int source = n + 2;
	int dest = n+3;
	pii residual[n+4][n+4];
	rep(i, 0, n){
		neighbor[i].pb(n);
		neighbor[i].pb(n+1);
		neighbor[n].pb(i);
		neighbor[n+1].pb(i);
		residual[i][n] = pii(1, a[i]);
		residual[i][n+1] = pii(1, b[i]);
		residual[n][i] = pii(0, 0);
		residual[n+1][1] = pii(0, 0);

		neighbor[source].pb(i);
		residual[source][i] = pii(1, MAXINT); 
	}

	neighbor[n].pb(dest);
	neighbor[n+1].pb(dest);
	residual[n][dest] = pii(p, MAXINT);
	residual[n+1][dest] = pii(s, MAXINT);

	int flow = 0;
	while(true){
		int parent [n+4];
		memset_array(parent, -1, n+4);
		queue<int> q;
		q.push(source);
		parent[source] = source;
		while(!q.empty()){
			int node = q.front(); q.pop();
			for(list<int>::iterator it = neighbor[node].begin(); 
							it != neighbor[node].end(); it++){
				if(residual[node][*it].fi > 0 && 
						residual[node][*it].sn > 0 && parent[*it] == -1){
					parent[*it] = node;
					q.push(*it);
				}
			}
		}
		if(parent[dest] == -1) break;

		int min_edge = MAXINT;
		int current_node = dest;
		while(current_node != parent[current_node]){
			cout << current_node << " ";
			min_edge = min(min_edge, residual[parent[current_node]][current_node].sn);
			current_node = parent[current_node];
		}
		cout << endl;

		flow += min_edge;

		current_node = dest;
		while(current_node != parent[current_node]){
			residual[parent[current_node]][current_node].sn -= min_edge;
			residual[parent[current_node]][current_node].fi -= 1;
			residual[current_node][parent[current_node]].sn += min_edge;
			residual[current_node][parent[current_node]].fi += 1;
			current_node = parent[current_node];

		}

	}

	cout << flow << endl;
	rep(i, 0, n){
		if(residual[i][n].fi == 0) cout << i << " ";
	}
	cout << endl;
	rep(i, 0, n){
		if(residual[i][n+1].fi == 0) cout << i << " ";
	}
	cout << endl;

	
	return 0;
}