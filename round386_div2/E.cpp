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
	int n, m; cin >> n >> m;
	if(m > n) m = n;
	int odd_in_m = (m+1)/2;
	int even_in_m = m/2;
	bool check[m+1];
	memset_array(check, false, m+1);

	int a[n];
	si odd, even;
	rep(i, 0, n){
		cin >> a[i];
		if(a[i] % 2 == 0){
			if(even.find(a[i]) == even.end()){
				even.insert(a[i]);
				if(a[i] <= m){
					check[a[i]] = true;
					even_in_m--;
				}
			}
			else a[i] = 0;
		}

		if(a[i] % 2 == 1){
			if(odd.find(a[i]) == odd.end()){
				odd.insert(a[i]);
				if(a[i] <= m){
				 	check[a[i]] = true;
				 	odd_in_m--;
				}
			}
			else a[i] = 0;
		}
	}

	// sort(a, a+n, greater<int>());
	// rep(i, 0, n){
	// 	if(a[i] & 2 == 0){
	// 		if(even.find(a[i]) == even.end() && even.size() < n/2){
	// 			even.insert(a[i]);
	// 		}
	// 		else a[i] = 0;
	// 	}

	// 	if(a[i] & 2 == 1){
	// 		if(odd.find(a[i]) == odd.end() && odd.size() < n/2){
	// 			odd.insert(a[i]);
	// 		}
	// 		else a[i] = 0;
	// 	}
	// }
	// print_array(a, n);
	// cout << even_in_m << even.size() << odd_in_m << odd.size() << endl; 

	if(even.size() + even_in_m < n/2 || odd.size() + odd_in_m < n/2){
		cout << - 1 << endl;
		return 0;
	}

	int num_of_change = 0;
	int run_odd = 1, run_even = 2, pos = 0;
	while(odd.size() < n/2 && pos < n){
		if(a[pos] == 0){
			while(check[run_odd]){
				run_odd += 2;
			}
			a[pos] = run_odd;
			num_of_change++;
			odd.insert(run_odd);
			run_odd += 2; 
		}
		pos++;
	}
	pos = 0;
	while(even.size() < n/2 && pos < n){
		if(a[pos] == 0){
			while(check[run_even]){
				run_even += 2;
			}
			a[pos] = run_even;
			num_of_change++;
			even.insert(run_even);
			run_even += 2; 
		}
		pos++;
	}

	if(odd.size() < even.size()){
		int num = odd.size();
		int pos = 0;
		while(num < n/2){
			if(a[pos] % 2 == 0){
				while(check[run_odd]){
					run_odd += 2;
				}
				a[pos] = run_odd;
				num_of_change++;
				run_odd += 2;
				num++;
			}
			pos++;
		}
	}

	if(odd.size() > even.size()){
		int num = even.size();
		int pos = 0;
		while(num < n/2){
			if(a[pos] % 2 == 1){
				while(check[run_even]){
					run_even += 2;
				}
				a[pos] = run_even;
				num_of_change++;
				run_even += 2;
				num++;
			}
			pos++;
		}
	}
	cout << num_of_change << endl;
	print_array(a, n);

	
	return 0;
}