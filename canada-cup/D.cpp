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
// #include <priority_queue>

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

struct cmp_ll
{
	bool operator()(ll a, ll b){
		return a > b;
	}
};



/////////////////////////////////////////////////////////////////////////////
// NEVER USE NAME : DISTANCE FOR FUNCTION
////////////////////////////////////////////////////////////////////////////
// compare_lexical_string("huy", "huy") will return false
bool compare_pll(pll a, pll b){
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.sn < b.sn;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pll> ball(n-1);
	// read first team
	ll first_ball, dull;
	cin >> first_ball >> dull;
	rep(i, 0, n - 1){
		cin >> ball[i].fi >> ball[i].sn;
		ball[i].sn = ball[i].sn - ball[i].fi + 1;
	}
	sort(ball.begin(), ball.end(), compare_pll);
	// rep(i, 0, n-1){
	// 	cout << "ball " << i <<": " << ball[i].fi << " " << ball[i].sn << endl;
	// }
	int left = 0;
	int right = 1;
	rep(i, 0, n-1){
		if(ball[i].fi > first_ball){
			right = n - i;
			break;
		}
	} 
	// cout << "right: " << right << endl;

	// check if valid
	while(right - left > 1){
		bool ok = false;
		int mid = (right + left)/2;
		int cur_pos = n-2;
		// there are mid - 1 teams which are better
		priority_queue<ll, vector<ll>, cmp_ll> cur_thres;
		ll cur_first_ball = first_ball;
		while(cur_pos >= 0){
			for(int i = cur_pos; i >= -1; i--){
				if(i != -1 && ball[i].fi > cur_first_ball) cur_thres.push(ball[i].sn);
				else{
					cur_pos = i;
					break;
				}
			}
			cout << "mid: " << mid <<" " << cur_thres.size() << endl;
			if(cur_thres.size() <= mid - 1){
				ok = true;
				break;
			}
			else{
				int cur_size = cur_thres.size();
				for(int i = 0; i < cur_size - (mid-1); i++){
					// cout << "i: " << i << endl;
					cur_first_ball = cur_first_ball - cur_thres.top();
					cur_thres.pop();
				}
				if(cur_first_ball < 0) break;
			}
			cout << "mid: " << mid <<" " << cur_thres.size() << endl;
			cout << "mid: " << mid << " cur_thres: " << cur_first_ball << endl;
		}
		if(cur_first_ball >= 0 && cur_pos < 0) ok = true;
		if(ok){
			right = mid;
		}
		else left = mid;
	}
	cout << right << endl;
	
	return 0;
}