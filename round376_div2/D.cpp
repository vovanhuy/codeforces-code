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

int n, c;
vector<pii> belong, not_belong;
vector<int> word[500005];

void process(vi a, vi b){
	// i < n-1
	int x, y;
	x = y = -1;
	rep(i, 0, min(a.size(), b.size())){
		if(a[i] != b[i]){
			x = a[i];
			y = b[i];
			break;
		}
	}

	if(x == -1){
		if(a.size() > b.size()) not_belong.pb(make_pair(0, c-1));
		else belong.pb(make_pair(0, c-1));
	}
	else{
		if(x < y){
			not_belong.pb(make_pair(c-y+1, c-x));
			// left_belong.pb(make_pair(0, c-y));
			// right_belong.pb(make_pair(c-x+1, c));
		}
		else if(x > y){
			belong.pb(make_pair(c-x+1, c-y));
		}
	}
}


pii find_intersection(){
	//belong
	
	int left = -1;
	int right = c+1;
	if(belong.size() == 0) return make_pair(0, c-1);
	rep(i, 0, belong.size()){
		if(belong[i].fi > left) left = belong[i].fi;
		if(belong[i].sn < right) right = belong[i].sn;
	}
	return pii(left, right);
	
	
}



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>c;
	rep(i, 0, n){
		int len; cin >> len;
		word[i] = vi(len);
		rep(j, 0, len){
			cin >> word[i][j];
		}
	}

	rep(i, 0, n-1){
		process(word[i], word[i+1]);
	}

	pii thuoc = make_pair(0, c-1);
	if(!belong.empty()){
		rep(i, 0, belong.size()){
			if(belong[i].first > thuoc.fi) thuoc.fi = belong[i].fi;
			if(belong[i].sn < thuoc.sn) thuoc.sn = belong[i].sn;
		}
	}

	set<int> possibilities;
	rep(i, thuoc.fi, thuoc.sn + 1) possibilities.insert(i);
	rep(i, 0, not_belong.size()){
		if(possibilities.empty()) break;
		si::iterator it = possibilities.lower_bound(not_belong[i].fi);
		if(it != possibilities.end()){
			while(it != possibilities.end() && *it <= not_belong[i].sn){
				possibilities.erase(it++);
			}
		}
	}

	if(possibilities.empty()) cout << -1 << endl;
	else cout << *possibilities.begin() << endl;




	
	return 0;
}