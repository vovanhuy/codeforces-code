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
pll BIT[100000 + 1];

int n; 
ll a[100005];
void init(){
	for(int i = 0; i <= n; i++){
		BIT[i] = pll(0, 0);
	}
}

pll prefix_sum(int idx){
	pll sum = pll(0, 0);
	while(idx > 0){
		sum.fi += BIT[idx].fi;
		sum.sn += BIT[idx].sn;
		idx -= (idx & -idx);
	}

	return sum;
}

pll interval_sum(int a, int b){
	pll sum_b = prefix_sum(b);
	pll sum_a = prefix_sum(a-1);
	return pll(sum_b.fi - sum_a.fi, sum_b.sn - sum_a.sn);
}


void update(int idx, pll val){
	assert(idx > 0);
	while(idx <= n){
		BIT[idx].fi += val.fi;
		BIT[idx].sn += val.sn;
		idx += (idx & -idx);
	}
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) cin >> a[i];

	ll S = 0, Srl = 0;
	rep(i, 1, n+1){
		pll greater = interval_sum(a[i]+1, n);
		S += greater.fi;
		Srl += greater.sn * (n - i + 1);
		update(a[i], pll(1, i));
	}

	// cout << S << " " << Srl << endl;

	double denominator = (double)(n+1)*(double)n/2.0;
	double expectation = 0;
	rep(i, 0, n){
		double di = (double)i;
		expectation += (double)(n - i)*(di*di + di);
	}

	cout << setprecision(20) << S + (-Srl + expectation/4)/denominator << endl;
	return 0;
}