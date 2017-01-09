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
#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n-1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define sn second
	

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

template <typename T>
void print_array(T arr[], int size_arr){
	rep(i, 0, size_arr){
		cout << arr[i] << " ";
	}
	cout << endl;
}
template <typename T>
void memset_array(T arr[], T value, int size_arr){
	rep(i, 0, size_arr){
		arr[i] = value;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string day1, day2; cin >> day1 >> day2;
	map<string, int> m;
	m["monday"] = 1;
	m["tuesday"] = 2;
	m["wednesday"] = 3;
	m["thursday"] = 4;
	m["friday"] = 5;
	m["saturday"] = 6;
	m["sunday"] = 7;

	int distance = (m[day2] - m[day1] + 7)%7;
	if(distance == 3 || distance == 0 || distance == 2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}