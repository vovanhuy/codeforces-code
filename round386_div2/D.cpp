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
	int n, k, a, b; cin >> n >> k >> a >> b;
	char one = 'G', two = 'B';
	if(a < b){
		int temp = b;
		char temp_c = two;
		b = a;
		a = temp;

		two = one;
		one = temp_c;
	}
	int slot_of_a = a % k == 0? a/k : a/k + 1;
	if(b < slot_of_a - 1){
		cout << "NO" << endl;
		return 0;
	}

	vi A(slot_of_a);
	rep(i, 0, slot_of_a - 1){
		A[i] = k;
	}
	A[slot_of_a - 1] = a - k * (slot_of_a - 1);

	b = b - (slot_of_a - 1);
	int slot_of_b = b % k == 0? b/k : b/k + 1;
	if(slot_of_b != 0){
		vi B(slot_of_b);
		rep(i, 0, slot_of_b - 1){
			B[i] = k;
		}
		B[slot_of_b - 1] = b - k * (slot_of_b - 1);
		int count = slot_of_b - 1;
		int pos = 0;
		while(count > 0){
			if(A[pos] > 1){
				A[pos]--;
				pos = (pos + 1) % slot_of_a;
				count--;
			}
			else{
				pos = (pos + 1) % slot_of_a;
			}
		}
		rep(i, 0, slot_of_a){
			rep(j, 0, A[i]){
				cout << one;
			}
			if(i != slot_of_a - 1) cout << two;
		}
		rep(i, 0, slot_of_b){
			rep(j, 0, B[i]){
				cout << two;
			}
			if(i != slot_of_b - 1) cout << one;
		}
		cout << endl;
	}
	else{
		rep(i, 0, slot_of_a){
			rep(j, 0, A[i]){
				cout << one;
			}
			if(i != slot_of_a - 1) cout << two;
		}
		cout << endl;
	}
	


	return 0;
}