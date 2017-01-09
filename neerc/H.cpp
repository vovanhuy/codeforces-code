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
// compare_lexical_string("huy", "huy") will return false


bool match(string t, string pattern){
	if(t.length() != pattern.length()) return false;
	rep(i, 0, t.length()){
		if(t[i] != pattern[i] && pattern[i] != '?') return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	string file_name[n];
	rep(i, 0, n) cin >> file_name[i];
	string del[m];
	set<int> file_del;
	int size;
	bool valid = true;
	rep(i, 0, m){
		int tmp; cin >> tmp;
		file_del.insert(tmp-1);
		del[i] = file_name[tmp-1];
		
		if(i > 0 && del[i].length() != size){
			valid = false;
			break;
		}
		size = del[i].length();
	}
	// rep(i, 0, m) cout << del[i] << endl;
	if(!valid){
		cout << "No" << endl;
		return 0;
	}
	else{
		//find pattern
		string s = del[0];
		rep(j, 0, size){
			rep(i, 1, m){
				if(del[i][j] != s[j]){
					s[j] = '?';
					break;
				}
			}
		}
		// cout << s << endl;
		rep(i, 0, n){
			if(file_del.find(i) == file_del.end()){
				if(match(file_name[i], s)){
					cout << "No" << endl;
					return 0;
				}
			}
		}
		cout << "Yes" << endl;
		cout << s << endl;
	}


	
	return 0;
}