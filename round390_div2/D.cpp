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
	int n, k ; cin >> n >> k;
	vector< pair<pii, int> > coupon(n);
	multiset<int> s;
	rep(i, 0, n){
		cin >> coupon[i].fi.fi >> coupon[i].fi.sn;
		coupon[i].sn = i;
	}

	sort(coupon.begin(), coupon.end());
	// rep(i, 0, n){
	// 	cout << coupon[i].fi.fi << " " <<coupon[i].fi.sn << " " << coupon[i].sn << endl;
	// }
	int dist[n];
	rep(i, 0, n){
		if(i + 1 < k){
			dist[i] = 0;
			s.insert(coupon[i].fi.sn);
		}
		else{
			int left = coupon[i].fi.fi;
			int right;
			if(s.size() == 0) right = coupon[i].fi.sn;
			else{
				if(coupon[i].fi.sn <= *s.begin()){
					right = coupon[i].fi.sn;
				}
				else{
					s.insert(coupon[i].fi.sn);
					right = *s.begin();
					s.erase(s.begin());
				}
			}
			if(right >= left) dist[i] = right-left + 1;
			else dist[i] = 0;
		}
	}

	// print_array(.dist, n);
	int maxx = 0;
	int argmax;
	rep(i, 0, n){
		if(dist[i] > maxx){
			maxx = dist[i];
			argmax = i;
		}
	}
	cout << maxx << endl;
	if(maxx == 0){
		rep(i, 0, k){
			if(i == k - 1) cout << i + 1 << endl;
			else cout << i + 1 << " ";
		}
	}
	else{
		int right = dist[argmax] + coupon[argmax].fi.fi - 1;
		int run = 0;
		while(k > 1){
			if(coupon[run].fi.sn >= right){
				cout << coupon[run].sn + 1 << " ";
				k--;
			}
			run++;
		}
		cout << coupon[argmax].sn + 1 << endl;
	}
	return 0;
}