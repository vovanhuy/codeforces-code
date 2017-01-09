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
int n, m;
int d[100005], a[100005];



bool pass(int pos){
	int remaining_day = pos+1;
	bool check[m];
	memset_array(check, false, m);
	while(pos >= 0){
		if(d[pos] != 0 && !check[d[pos] - 1]){
			remaining_day = min(remaining_day, pos+1);
			if(remaining_day >= 1 + a[d[pos]-1]){
				remaining_day -= (1 + a[d[pos]-1]);
				check[d[pos] - 1] = true;
			}
			else return false;
		}
		pos--;
	}
	rep(i, 0, m) if(!check[i]) return false;

} 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >>n>>m;
	rep(i, 0,n) cin >>d[i];
	rep(i, 0, m) cin >> a[i];

	int left = 0, right = n-1;
	rep(i, 0, m) left += 1 + a[i];
	left--;
	if(left >= n){
		cout << -1 << endl;
		return 0;
	}

	while(right - left > 0){
		int mid = (right + left)/2;
		if(pass(mid)) right = mid;
		else left = mid + 1;
	}

	if(pass(left)) cout << left+1 << endl;
	else cout << -1 << endl;
	
	
	return 0;
}