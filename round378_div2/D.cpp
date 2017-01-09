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
typedef pair<pii, int> piii;
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

map<pii, priority_queue<pii> > m;

void add_to_map_aux(pii r, pii k){
	m[r].push(k);
}
void add_to_map(int a, int b, int c, int index){
	if(a == b && b == c){
		add_to_map_aux(pii(a, b), pii(c, index));
	}
	else if(a == b && b != c){
		add_to_map_aux(pii(a, b), pii(c, index));
		add_to_map_aux(pii(min(a, c), max(a,c)), pii(b, index));
	}
	else if(a == c && a != b){
		add_to_map_aux(pii(a, c), pii(b, index));
		add_to_map_aux(pii(min(a, b), max(a, b)), pii(c, index));
	}
	else if(b == c && a != b){
		add_to_map_aux(pii(b, c), pii(a, index));
		add_to_map_aux(pii(min(b, a), max(b, a)), pii(c, index));
	}
	else{
		add_to_map_aux(pii(min(a, b), max(a, b)), pii(c, index));
		add_to_map_aux(pii(min(a, c), max(a, c)), pii(b, index));
		add_to_map_aux(pii(min(b, c), max(b, c)), pii(a, index));
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int a, b, c;
	rep(i, 0, n){
		cin >> a >> b >> c;
		add_to_map(a, b, c, i+1);
	}
	int cur_max = 0;
	int num_of_stone;
	int index1, index2;
	for(auto el: m){
		priority_queue<pii> cur_queue = el.sn;
		pii cur_pii = el.fi;
		// cout << cur_pii.fi << " " << cur_pii.sn << endl;
		
		int first_max = min(cur_pii.fi, min(cur_pii.sn, cur_queue.top().fi));
		if(first_max > cur_max){
			cur_max = first_max;
			num_of_stone = 1;
			index1 = cur_queue.top().sn;
		}
		if(cur_queue.size() > 1){
			pii first_el = cur_queue.top();
			cur_queue.pop();
			pii second_el = cur_queue.top();
			// cout << "el: " << first_el.fi << " " << second_el.fi << endl;
			int pair_max = first_el.fi + second_el.fi;
			int second_max = min(cur_pii.fi, min(cur_pii.sn, pair_max));
			if(second_max > cur_max){
				num_of_stone = 2;
				index1 = first_el.sn;
				index2 = second_el.sn;
				cur_max = second_max;
			}
		}
	}

	// cout << cur_max << endl;
	cout << num_of_stone << endl;
	if(num_of_stone == 1) cout << index1 << endl;
	else cout << index1 << " " << index2 << endl;

	
	return 0;
}