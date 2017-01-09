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
#define modulo 1000003
	

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
		if(i != v.size() - 1) cout << " ";
	}
}

template <typename T>
void memset_array(T arr[], T value, int size_arr){
	rep(i, 0, size_arr){
		arr[i] = value;
	}
}


/////////////////////////////////////////////////////////////////////////////
// NEVER USE NAME : DISTANCE FOR FUNCTION
////////////////////////////////////////////////////////////////////////////
int price[50001];
int gain[50001];
int C;

int gcd(int a, int b){
	if(a * b == 0) return a + b;
	if(a < b) return gcd(b, a);
	return gcd(b, a%b);
}

vector<pll> real_packs;
int solve(){
	ll dp[C + 1];
	memset(dp, (ll)0, sizeof(dp));
	for(int i = 0; i < real_packs.size(); i++){
		for(int v = 1; v <= C; v++){
			if(v >= real_packs[i].fi)
				dp[v] = max(dp[v], dp[v - real_packs[i].fi] + real_packs[i].sn);
		}
	}
	return dp[C];
}


int huy_solve(){
	ll dp[C+1];
	memset_array(dp, (ll)0, C+1);
//	dp[0] = ;
	rep(i, 0, C+1){
		rep(j, 0, real_packs.size()){
			if(i >= real_packs[j].fi) dp[i] = max(dp[i], dp[i-real_packs[j].fi]+real_packs[j].sn); 
		}		
	}
	
	return dp[C];
}

ll dp[2000000+1];


int solve_01(){
	// cout << C << endl;
	// cout << "here" << endl;
	// ll dp[C+1];
	// cout << "then here" << endl;
	
	memset_array(dp, (ll)0, C+1);
	for(int i = 0; i < real_packs.size(); i++){
		for(int v = C; v >= 0; v--){
			if(v >= real_packs[i].fi)
				dp[v] = max(dp[v], dp[v - real_packs[i].fi] + real_packs[i].sn);
 		}
	}

	return dp[C];
}
//struct cmp{
	bool cmp(pll a, pll b){
		if(a.fi != b.fi) return a.fi < b.fi;
		return a.sn > b.sn;
	}
//};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> C;
	int N, P; cin >> N >> P;
	vector<pll> packs; 
	int a[N + 1], t[N+1];
//	shares.push_back(mk(-1, 0));
	for(int i = 1; i <= N; i++){
		cin >> a[i] >> t[i];
		t[i] -= a[i];
//		cout << "share " << i << " " << a[i] << " " << t[i] << endl;
	}
	ll price, gain;
	int r, x, y;
	for(int i = 0; i < P; i++){
		price = gain = 0;
		cin >> r;
		for(int j = 0; j < r; j++){
			cin >> x >> y;
			price += y * a[x];
			gain += y * t[x];
		}
	
		if(gain > 0 && price <= C)
			packs.push_back(mp(price, gain));
//		cout << " for P " << i << " " << price << " " << gain<< endl;
	}
	real_packs = packs;
		int cur_gcd = gcd(real_packs[0].fi, real_packs[1].fi);
		for(int i = 2; i < real_packs.size(); i++){
			cur_gcd = gcd(real_packs[i].fi, cur_gcd);

			if(cur_gcd == 1) break;
		}
		// cout << cur_gcd << endl;
		if(cur_gcd != 1){
			C = C/cur_gcd;
			for(int i = 0; i < real_packs.size(); i++)
			real_packs[i].fi = real_packs[i].fi / cur_gcd; 
		}

	int ans = solve_01();
	cout << ans << endl;
	return 0;
}