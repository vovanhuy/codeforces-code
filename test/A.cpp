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
	srand (time(NULL));
	bool ok[10000];
	memset_array(ok, true, 10000);
	int num = 10000;
	rep(times, 0, 49){
		// printf("%d\n", num);
		int bu, co;
		int K = rand() % num + 1;
		int pos = 0;
		rep(j, 0, 10000){
			if(ok[j]) K--;
			if(K == 0){
				pos = j;
				break;
			}
		}


		int a1, b1, c1, d1;
		int tmp1 = pos;
		a1 = tmp1/1000;
		tmp1 = tmp1 % 1000;
		b1 = tmp1/100;
		tmp1 = tmp1 % 100;
		c1 = tmp1/10;
		tmp1 = tmp1 % 10;
		d1 = tmp1;

		if(times < 2){
			a1 = 4*times;
			b1 = 4*times + 1;
			c1 = 4*times + 2;
			d1 = 4*times + 3;
		}

		cout << a1<<b1<<c1<<d1<<endl;
		cout << flush;
		cin>>bu>>co;
		if(bu == 4 && co == 0) return 0;


		rep(i, 0, 10000){
			if(ok[i]){
				int a, b, c, d;
				int tmp = i;
				a = tmp/1000;
				tmp = tmp % 1000;
				b = tmp/100;
				tmp = tmp % 100;
				c = tmp/10;
				tmp = tmp % 10;
				d = tmp;

				// cout << a << b<<c<<d<<endl;
					
				
				int bull, cow;
				bull = cow = 0;
				if(a == a1) bull++;
				if(b == b1) bull++;
				if(c == c1) bull++;
				if(d == d1) bull++;

				rep(k, 0, 10){
					if((a == k || b == k || c == k || d == k) && (a1 == k || b1 == k || c1 == k || d1 == k) &&
						!((a==k && a1 == k) || (b==k&&b1 == k) || (c==k&&c1==k)||(d==k && d1==k))){

							cow++;
							// cout << k << endl;
						}
				}
				// cout << bull << " " << cow << endl;
				if(bull != bu || cow != co){
					ok[i] = false;
					num--;
				}
				// else cout << i << endl;
			}
		}
	}

	rep(i, 0, 10000){
		if(ok[i]){
			int a, b, c, d;
			int tmp = i;
			a = tmp/1000;
			tmp = tmp % 1000;
			b = tmp/100;
			tmp = tmp % 100;
			c = tmp/10;
			tmp = tmp % 10;
			d = tmp;

			cout <<a<<b<<c<<d<<endl;
			cout << flush;
		}
	}
	
	return 0;
}