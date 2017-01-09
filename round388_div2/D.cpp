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
struct comp_pii
{
	bool operator()(pii a, pii b){
		return a.fi > b.fi;
	}
};


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int max_person[n];
	si s[n];
	memset_array(max_person, -1, n); 
	rep(i, 0, n){
		int a, b;
		cin >> a >> b;
		s[a-1].insert(b);
		max_person[a-1] = max(max_person[a-1], b);
	}

	int q; cin >> q;
	set<pii, comp_pii> maxx;
	rep(i, 0, n){
		if(max_person[i] != -1){
			maxx.insert(pii(max_person[i], i));
		}
	}

	rep(question, 0, q){
		int num; cin >> num;
		int p[num];
		rep(i, 0, num){
			cin >> p[i]; p[i]--;
			if(max_person[p[i]] != -1) maxx.erase(pii(max_person[p[i]], p[i]));
		}
		if(maxx.size() == 0){
			cout << 0 << " " << 0<< endl;
		}
		else if(maxx.size() == 1){
			int id = maxx.begin()->sn;
			cout << id + 1 << " " << *s[id].begin() << endl;
		}
		else{
			int id = maxx.begin()->sn;
			int lim = (++maxx.begin())->fi;
			// cout << "lim " << lim << endl;
			cout << id + 1<< " " << *s[id].lower_bound(lim) << endl;

		}

		rep(i, 0, num){
			if(max_person[p[i]] != -1) maxx.insert(pii(max_person[p[i]], p[i]));
		}

	}
	return 0;
}