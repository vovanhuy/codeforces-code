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
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin>>n>>m>>k;
	int color[n];
	vector<int> neighbor[n];
	set<int> neighbor_set[n];
	rep(i, 0, n) cin>>color[i];
	rep(i, 0, m){
		int x, y; cin >> x >> y;
		x--; y--;
		if(neighbor_set[x].find(y) == neighbor_set[x].end()){
			neighbor_set[x].insert(y);
			neighbor_set[y].insert(x);
			neighbor[x].pb(y);
			neighbor[y].pb(x);
		}
	}

	int component[n];
	memset_array(component, -1, n);
	int num_of_component = 0;
	rep(i, 0, n){
		if(component[i] == -1){
			component[i] = num_of_component++;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int current = q.front(); q.pop();
				rep(j, 0, neighbor[current].size()){
					if(component[neighbor[current][j]] == -1){
						component[neighbor[current][j]] = component[current];
						q.push(neighbor[current][j]);
					}
				}
			}
		}
	}

	vector<int> vec_component[num_of_component];
	rep(i, 0, n){
		vec_component[component[i]].pb(i);
	}

	int count = 0;
	rep(i, 0, num_of_component){
		vi current_component = vec_component[i];
		map<int, int> num_of_color;
		rep(j, 0, current_component.size()){
			if(num_of_color.find(color[current_component[j]]) != num_of_color.end()){
				num_of_color[color[current_component[j]]]++;
			}
			else num_of_color[color[current_component[j]]] = 1;
		}

		int max_num = 0;
		for(map<int, int>::iterator it = num_of_color.begin(); it != num_of_color.end(); it++){
			if(it->sn > max_num) max_num = it->sn;
		}
		count += current_component.size() - max_num;

	}

	cout << count << endl;



	
	return 0;
}