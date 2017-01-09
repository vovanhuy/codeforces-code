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
#include <unordered_map>

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

const int MOD = 1e9+7;
const int MAXLEN = 400005;
pll st[MAXLEN];
ll lazy[MAXLEN];
ll A[100005];
int n, m;



class matrix{
	public:
		ll one, two, four;

		matrix(){}

		matrix(ll a, ll b, ll c){
			one = a;
			two = b;
			four = c;
		} 

		void multiply(const matrix &b){
			ll new_one = (one*b.one + two*b.two) % MOD;
			ll new_two = (one*b.two + two*b.four) % MOD;
			ll new_four = (two*b.two + four*b.four) % MOD;

			one = new_one;
			two = new_two;
			four = new_four; 
		}

		pll mul_with_vector(pll x){
			ll new_one = (one*x.fi + two*x.sn) % MOD;
			ll new_two = (two*x.fi + four*x.sn) % MOD;
			return pll(new_one, new_two);
		}

		void operator=(const matrix &b){
			one = b.one;
			two = b.two;
			four = b.four;
		}

};

matrix identity(){
	return matrix(1, 0, 1);
}

matrix fibo_mat(){
	return matrix(1, 1, 0);
}

matrix mul_matrix(const matrix &a, const matrix &b){
	return matrix((a.one*b.one + a.two*b.two) % MOD, (a.one*b.two + a.two*b.four) % MOD, (a.two*b.two + a.four*b.four) % MOD);
}

matrix matrix_power[65];
unordered_map<ll, matrix> map_matrix;

void init(){
	rep(i, 0, MAXLEN) lazy[i] = 0;
	matrix_power[0] = fibo_mat();
	rep(i, 1, 65) matrix_power[i] = mul_matrix(matrix_power[i-1], matrix_power[i-1]);
}

matrix power(ll p){
	if(map_matrix.find(p) != map_matrix.end()){
		return map_matrix[p];
	}
	vi v;
	ll tmp = p;
	while(p > 0){
		v.pb(p % 2);
		p /= 2;
	}

	matrix res = identity();
	rep(i, 0, v.size()){
		if(v[i] == 1) res.multiply(matrix_power[i]);
	}
	map_matrix[tmp] = res;
	return res;
}

ll fibo(ll m){
	if( m == 1 || m == 2) return 1;
	else{
		matrix a = power(m - 3);
		return (a.one + a.two*2 + a.four) % MOD;
	}
}

pll sum_pll(pll a, pll b){
	return make_pair((a.fi + b.fi) % MOD, (a.sn + b.sn) % MOD);
}


void build(int id, int l, int r)
{
    if(r - l < 2){
        st[id] = pll(fibo(A[l] + 1), fibo(A[l]));
    }
    else{
        int mid = (l + r)/2;
        build(2*id + 1, l, mid);
        build(2*id + 2, mid, r);
        st[id] = sum_pll(st[2*id + 1], st[2*id + 2]);
    }
}

void update(int id, int l, int r, ll val){
	lazy[id] += val;
	matrix a = power(val);
	st[id] = a.mul_with_vector(st[id]);
}

void shift(int id, int l, int r){
	if(lazy[id] > 0){
		int mid = (l + r)/2;
		update(2*id + 1, l, mid, lazy[id]);
		update(2*id + 2, mid, r, lazy[id]);
		lazy[id] = 0;
	}
}

void update_range(int id, int l, int r, int x, int y, ll val){
	if(y <= l || r <= x){
		return;
	}
	if(x <= l && r <= y){
		update(id, l, r, val);
		return;
	}
	shift(id, l, r);
	int mid = (l + r)/2;
	update_range(2*id + 1, l, mid, x, y, val);
	update_range(2*id + 2, mid, r, x, y, val);
	st[id] = sum_pll(st[2*id + 1], st[2*id + 2]);
}

pll querry_range(int id, int l, int r, int x, int y){
	if(y <= l || r <= x) return pll(0, 0);
	if(x <= l && r <= y) return st[id];
	shift(id, l, r);
	int mid = (l + r)/2;
	pll l1 = querry_range(2*id + 1, l, mid, x, y);
	pll l2 = querry_range(2*id + 2, mid, r, x, y);
	return sum_pll(l1, l2);
}





/////////////////////////////////////////////////////////////////////////////
// NEVER USE NAME : DISTANCE FOR FUNCTION
////////////////////////////////////////////////////////////////////////////
// compare_lexical_string("huy", "huy") will return false
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	rep(i , 0, n) cin >> A[i];
	init();
	build(0, 0, n);
	int tp, x, y;
	ll val;
	rep(i, 0, m){
		cin >> tp >> x >> y;
		if(tp == 2){
			cout << querry_range(0, 0, n, x-1, y).sn << endl;
			// rep(i, 0, 4*n){
			// 	cout << st[i].sn << " ";
			// }
			// cout << endl;
			// print_array(lazy, 4*n);
		}
		else{
			cin >> val;
			update_range(0, 0, n, x-1, y, val);
			// rep(i, 0, 4*n){
			// 	cout << st[i].sn << " ";
			// }
			// cout << endl;
			// print_array(lazy, 4*n);
		}
	}
	// rep(i, 1, 12){
	// 	matrix ma = power((ll)i);
	// 	cout << ma.one << " " << ma.two << endl << ma.two << " " << ma.four << endl;
	// }
	
	
	return 0;
}