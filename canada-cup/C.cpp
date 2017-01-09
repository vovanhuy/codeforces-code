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

string reverse_string(string t){
	rep(i, 0, t.length()/2){
		char tmp = t[i];
		t[i] = t[t.length() - i - 1];
		t[t.length() - i - 1] = tmp;
	}
	return t;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	s = s+ s+ s;
	int pos[26];
	memset_array(pos, -1, 26);
	int f, e;
	char critic;
	rep(i, 27, 54){
		if(pos[s[i] - 'A'] == -1) pos[s[i]-'A'] = i;
		else{
			f = pos[s[i]-'A'];
			e = i;
			critic = s[i];
			cout << critic << endl;
			break;
		}
	}
	cout << e << " " << f << endl;
	char res[2][13];
	if(e-f == 1) cout << "Impossible" << endl;
	else{
		int l = (e-f-1)/2;
		string first = reverse_string(s.substr(e+1, 13-(l+1))) + s.substr(f, l+1);
		string second = s.substr(e-l+13, 27 - (e-l-27+13)) + s.substr(27, f-27) + reverse_string(s.substr(f+l+1, e-f-l-1));
		cout << first << endl;
		cout << second << endl;
	}
	return 0;
}