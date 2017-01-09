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
	int n, m, k; cin >> n >> m >> k;
	int gov[k];
	rep(i, 0, k){
		cin >> gov[i];
		gov[i]--;
	}

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

	int popu[num_compo];
	memset_array(popu, 0, num_compo);
	rep(i, 0, n){
		popu[compo[i]]++;
	}

	vector<int> pop_gov(k);
	int sum_pop = 0;
	rep(i, 0, k){
		pop_gov[i] = popu[compo[gov[i]]];
		sum_pop += pop_gov[i];
	}

	sort(pop_gov.begin(), pop_gov.end());
	int num_edge = 0;
	rep(i, 0, k-1){
		num_edge += (pop_gov[i] - 1) * pop_gov[i]/2;
	}
	num_edge += (pop_gov[k-1] + n - sum_pop)*(pop_gov[k-1] + n - sum_pop-1)/2;
	cout << num_edge - m << endl;

	
	return 0;
}