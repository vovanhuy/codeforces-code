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

struct lex_pii
{
	bool operator()(pii a, pii b){
		if(a.fi != b.fi) return a.fi < b.fi;
		else return a.sn < b.sn;
	}
};


template<typename T>
int find_length(T num){
	int count = 0;
	while(num > 0){
		count++;
		num /= 2;
	}
	return count;
}



/////////////////////////////////////////////////////////////////////////////
// NEVER USE NAME : DISTANCE FOR FUNCTION
////////////////////////////////////////////////////////////////////////////

struct comp_computer
{
	bool operator()(pii a, pii b){
		if(a.fi != b.fi) return a.fi > b.fi;
		else return a.sn < b.sn;
	}
};

int find_dis(int a, int b){
	int count = 0;
	while(a != b){
		count++;
		a = (a+1)/2;
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	set<int> set_p;
	pii p[n], s[m];
	vector<int> valid_computer[m];
	map<int, list<pii> > valid_socket;
	rep(i, 0, n){
		cin >> p[i].fi;
		set_p.insert(p[i].fi);
		p[i].sn = i;
	}
	rep(i, 0, m){
		cin>>s[i].fi;
		s[i].sn = i;
	}

	for(set<int>::iterator it = set_p.begin(); it != set_p.end(); it++){
		valid_socket[*it] = list<pii>();
	}

	sort(s, s+m);

	rep(i, 0, m){
		int tmp = s[i].fi;
		while(tmp > 1){
			if(set_p.find(tmp) != set_p.end()){
				valid_computer[i].pb(tmp);
				valid_socket[tmp].pb(pii(s[i].fi, s[i].sn));
			}
			tmp = (tmp+1)/2;
		}
		if(set_p.find(1) != set_p.end()){
			valid_computer[i].pb(1);
			valid_socket[1].pb(pii(s[i].fi, s[i].sn));
		}
	}

	int a[m], b[n];
	memset_array(a, 0, m);
	memset_array(b, 0, n);
	int c = 0, u = 0;

	bool available_socket[m];
	memset_array(available_socket, true, m);

	sort(p, p+n);
	per(i, 0, n){
		while(!valid_socket[p[i].fi].empty() && !available_socket[valid_socket[p[i].fi].begin()->sn]){
			valid_socket[p[i].fi].erase(valid_socket[p[i].fi].begin());
		}
		if(valid_socket[p[i].fi].size() != 0){
			pii current_socket = *valid_socket[p[i].fi].begin();
			c++;
			b[p[i].sn] = current_socket.sn + 1;
			int u_plus = find_dis(current_socket.fi, p[i].fi);
			a[current_socket.sn] = u_plus;
			u += u_plus;
			available_socket[current_socket.sn] = false;
			// valid_socket[p[i].fi].erase(valid_socket[p[i].fi].begin());
		}
	}





	cout << c << " " << u << endl;
	print_array(a, m);
	print_array(b, n);


	

	// initialise();
	// rep(i, 1, 10) add(i, 1);
	// rep(i, 1, 5) cout << graph[i]->freq << endl;

	// per(i, 1, 11) cout << find_node(i) << endl;
	// rep(i, 1, 5) cout << graph[i]->freq << endl;

	return 0;
}