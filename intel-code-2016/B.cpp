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

int n, m;
int table[20][20];

bool valid(){
	int count[n];
	memset_array(count, 0, n);
	rep(i, 0, n){
		rep(j, 0, m){
			if(table[i][j] != j+1) count[i]++;
		}
	}
	rep(i,0,n){
		if(count[i] > 2) return false;
	}
	return true;
}

void swap(int a, int b){
	rep(i, 0, n){
		int temp = table[i][a];
		table[i][a] = table[i][b];
		table[i][b] = temp;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	rep(i, 0, n){
		rep(j, 0, m){
			cin >> table[i][j];
		}
	}

	bool possible = false;
	rep(i, 0, m){
		rep(j, i+1, m){
			swap(i, j);
			if(valid()){
				possible = true;
				break;
			}
			swap(i, j);
		}
	}
	if(valid()) possible = true;

	if(possible) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}