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
// NEVER USE NAME : FIND FOR FUNCTION
////////////////////////////////////////////////////////////////////////////
// compare_lexical_string("huy", "huy") will return false
pll find_min(vector<ll> a, vector<ll> b, ll target){
	ll cur_min_dis = numeric_limits<ll>::max();
	pll argmin;
	rep(i, 0, a.size()){
		ll cur_target = a[i] - target;
		int critical_pos = lower_bound(b.begin(), b.end(), cur_target) - b.begin();
		if(critical_pos < b.size() && abs(cur_target - b[critical_pos]) < cur_min_dis){
			cur_min_dis = abs(cur_target - b[critical_pos]);
			argmin.fi = a[i];
			argmin.sn = b[critical_pos];
		}
		if(critical_pos > 0 && abs(cur_target - b[critical_pos-1]) < cur_min_dis){
			cur_min_dis = abs(cur_target - b[critical_pos-1]);
			argmin.fi = a[i];
			argmin.sn = b[critical_pos-1];
		}
	}
	return argmin;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<ll> a(n);
	ll original_a[n];
	ll sum_a = 0;
	rep(i, 0, n){
		cin >> original_a[i];
		a[i] = 2*original_a[i];
		sum_a += original_a[i];
	}
	int m; cin >> m;
	ll sum_b = 0;
	vector<ll> b(m);
	ll original_b[m];
	rep(i, 0, m){
		cin >> original_b[i];
		b[i] = 2*original_b[i];
		sum_b += original_b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll target = (sum_a - sum_b);

	// case there is no swap
	ll min_zero = abs(sum_a - sum_b);
	//case there is one swap
	pll argmin_one = find_min(a, b, target);
	ll min_one = abs(sum_a - sum_b + argmin_one.sn - argmin_one.fi);
	//case there is two swap
	// only if both a and b contain more than 1 element
	// construct 2 sum arrays
	pll argmin_two;
	ll min_two;
	if(a.size() > 1 && b.size() > 1){
		vector<ll> A;
		vector<ll> B;
		rep(i, 0, n){
			rep(j, i+1, n){
				A.pb(a[i] + a[j]);
			}
		}
		rep(i, 0, m){
			rep(j, i+1, m){
				B.pb(b[i] + b[j]);
			}
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		argmin_two = find_min(A, B, target);
		min_two = abs(sum_a - sum_b + argmin_two.sn - argmin_two.fi);
	}

	ll final_min;
	if(a.size() > 1 && b.size() > 1){
		final_min = min(min_zero, min(min_one, min_two));
	}
	else final_min = min(min_zero, min_one);
	

	cout << final_min << endl;
	if(final_min == min_zero){
		cout << 0 << endl;
	}
	else if (final_min == min_one){
		cout << 1 << endl;
		rep(i, 0, n){
			if(2*original_a[i] == argmin_one.fi){
				cout << i + 1 << " ";
				break;
			}
		}
		rep(i, 0, m){
			if(2*original_b[i] == argmin_one.sn){
				cout << i + 1 << endl;
				break;
			}
		}
	}
	else{
		cout << 2 << endl;
		// cout << argmin_two.fi << " " <<argmin_two.sn << endl;
		pii first = pii(-1, -1);
		rep(i, 0, n){
			rep(j, i+1, n){
				if(2*original_a[i] + 2*original_a[j] == argmin_two.fi){
					first.fi = i+1;
					first.sn = j+1;
					break;
				}
			}
			if(first.fi != -1) break;
		}
		pii second = pii(-1,-1);
		rep(i, 0, m){
			rep(j, i+1, m){
				if(2*original_b[i] + 2*original_b[j] == argmin_two.sn){
					second.fi = i+1;
					second.sn = j+1;
					break;
				}
			}
			if(second.fi != -1) break;
		}
		cout << first.fi << " " << second.fi << endl;
		cout << first.sn << " " << second.sn << endl;
	}

	
	return 0;
}