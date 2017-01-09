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
int n;
vi to_bit(int k){
	vi res(10);
	rep(i, 0, 10){
		if(k % 2 == 0) res[i] = 0;
		else res[i] = 1;
		k = k/2;
	}
	return res;
}

vector< vi > binary(1001);
int minn[1001];

void init(){
	rep(i, 1, 1001){
		binary[i] = to_bit(i);
		minn[i] = MAXINT;
	}
}

int find_length(int k){
	int res = 0;
	while(k > 0){
		res++;
		k /= 2;
	}
	return res;
}



int main(){
	init();
	scanf("%d", &n);
	rep(bit, 0, find_length(n)){
		// count bit i == 0
		int k = 0;
		rep(i, 1, n+1){
			if(binary[i][bit] == 0) k++;
		}
		printf("%d\n", k);
		rep(i, 1, n+1){
			if(binary[i][bit] == 0){
				printf("%d", i);
				k--;
				if(k == 0) printf("\n");
				else printf(" ");
			}
		}
		fflush(stdout);
		int ans[n+1];
		rep(i, 1, n+1) scanf("%d", &ans[i]);
		rep(i, 1, n+1){
			if(binary[i][bit] != 0) minn[i] = min(minn[i], ans[i]);
		}


		rep(i, 1, n+1){
			if(binary[i][bit] == 1) k++;
		}
		printf("%d\n", k);
		rep(i, 1, n+1){
			if(binary[i][bit] == 1){
				printf("%d", i);
				k--;
				if(k == 0) printf("\n");
				else printf(" ");
			}
		}
		fflush(stdout);
		rep(i, 1, n+1) scanf("%d", &ans[i]);
		rep(i, 1, n+1){
			if(binary[i][bit] != 1) minn[i] = min(minn[i], ans[i]);
		}
	}
	printf("-1\n");
	rep(i, 1, n+1){
		printf("%d", minn[i]);
		if(i == n) printf("\n");
		else printf(" ");
	}
	fflush(stdout);
	
	return 0;
}