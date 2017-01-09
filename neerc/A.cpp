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
struct my_cmp
{
	bool operator()(pii a, pii b){
		if(a.fi != b.fi) return a.fi > b.fi;
		else return a.sn > b.sn;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int r[n];
	rep(i, 0, n) cin >> r[i];

	int left = 0;
	int right = 101;
	rep(i, 0, n) if(r[i] < right) right = r[i];

	while(right - left > 0){
		int mid = (right + left + 1)/2;
		int cur_r[n];
		rep(i, 0, n) cur_r[i] = r[i] - mid;

		int cur_max = 0;
		int cur_sum = 0;
		rep(i, 0, n){
			if(cur_r[i] > cur_max) cur_max = cur_r[i];
			cur_sum += cur_r[i];
		}
		if(cur_max <= cur_sum - cur_max){
			left = mid;
		}
		else right = mid-1;
	}

	cout << left << endl;
	if(left == 0){
		vector<string> res;
		int count = 0;
		vector<char> v(n);
		rep(i, 0, n) v[i] = '0';
		string s(v.begin(), v.end());

		vector<pii> sii;
		rep(i, 0, n) sii.pb(make_pair(r[i], i));
		sort(sii.begin(), sii.end());
		for(int i = n-1; i >= 0; i -= 2){
			if(i > 2 || i == 1){
				s[sii[i].sn] = '1';
				s[sii[i-1].sn] = '1';
				count += sii[i].fi;
				rep(j, 0, sii[i].fi) res.pb(s);
				s[sii[i].sn] = '0';
				s[sii[i-1].sn] = '0';
			}
			else{
				s[sii[2].sn] = '1';
				s[sii[1].sn] = '1';
				s[sii[0].sn] = '1';
				count += sii[2].fi;
				rep(j, 0, sii[2].fi) res.pb(s);
			}
		}

		cout << count << endl;
		rep(i, 0, count) cout << res[i] << endl;

	}
	else{
		vector<string> res;
		int count = 0;
		vector<char> v(n);
		rep(i, 0, n) v[i] = '0';
		string s(v.begin(), v.end());

		set<pii, my_cmp> sii;
		rep(i, 0, n){
			if(r[i] - left != 0)
				sii.insert(make_pair(r[i] - left, i));
		}

		while(sii.size() > 3 || sii.begin()->first > 1 || sii.size() == 2){
			count++;
			set<pii>::iterator it2 = sii.begin();
			set<pii>::iterator it1 = it2++;
			pii first = *it1;
			pii second = *it2;
			s[it1->sn] = '1';
			s[it2->sn] = '1';
			res.pb(s);
			s[it1->sn] = '0';
			s[it2->sn] = '0';

			sii.erase(it1);
			sii.erase(it2);

			first.fi--;
			second.fi--;
			if(first.fi != 0) sii.insert(first);
			if(second.fi != 0) sii.insert(second);
		}

		if(sii.size() > 0){
			count++;
			set<pii>::iterator it3 = sii.begin();
			set<pii>::iterator it1 = it3++;
			set<pii>::iterator it2 = it3++;
			pii first = *it1;
			pii second = *it2;
			pii third = *it3;
			s[it1->sn] = '1';
			s[it2->sn] = '1';
			s[it3->sn] = '1';
			res.pb(s);
			s[it1->sn] = '0';
			s[it2->sn] = '0';
			s[it3->sn] = '0';

			sii.erase(it1);
			sii.erase(it2);
			sii.erase(it3);

			first.fi--;
			second.fi--;
			third.fi--;
			if(first.fi != 0) sii.insert(first);
			if(second.fi != 0) sii.insert(second);
			if(third.fi != 0) sii.insert(third);

		}

		cout << count << endl;
		rep(i, 0, count) cout << res[i] << endl;



	}
	
	return 0;
}