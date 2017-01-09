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


int len, m;
string s;
vector<int> position[26];
set<int> remaining_position;

void construct_position(){
	rep(i, 0, len){
		position[s[i] - 'a'].pb(i);
	}
}

void fill_set(){
	remaining_position.clear();
	rep(i, 0, len - m + 1){
		remaining_position.insert(i);
	}
}

int find_last_character(){
	fill_set();
	rep(i, 0, 26){
		rep(j, 0, position[i].size()){
			set<int>::iterator it = remaining_position.lower_bound(position[i][j] - m + 1);
			// if it == end() then keep going
			while(it != remaining_position.end() && *it <= position[i][j]){
				remaining_position.erase(it++);
			}
			if(remaining_position.empty()){
				return i;
			}
		}
	}
}

void truncated_find_last_character(int critic_character){
	fill_set();
	rep(i, 0, critic_character){
		rep(j, 0, position[i].size()){
			set<int>::iterator it = remaining_position.lower_bound(position[i][j] - m + 1);
			// if it == end() then keep going
			while(it != remaining_position.end() && *it <= position[i][j]){
				remaining_position.erase(it++);
			}
		}
	}
}


int find_min_num_to_cover(int character){
	int result = 0;
	int begin_position_in_array = 0;
	while(!remaining_position.empty()){
		// cout << remaining_position.size();
		result++;
		int first_pos = *remaining_position.begin();
		int position_to_use;
		rep(i, begin_position_in_array, position[character].size()){
			if(position[character][i] > first_pos + m - 1){
				position_to_use = position[character][i - 1];
				begin_position_in_array = i;
				break;
			}
			else if(i == position[character].size() - 1){
				position_to_use = position[character][i];
			}
		}
		while(!remaining_position.empty() && *remaining_position.begin() <= position_to_use){
			remaining_position.erase(remaining_position.begin());
		}
	}
	return result;
}

void print_sequence(int critic_character){
	rep(i, 0, critic_character){
		rep(j, 0, position[i].size()){
			cout << (char)('a' + i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// input
	m; cin >> m;
	cin >> s;
	len = s.length();
	construct_position();
	int critic_character = find_last_character();
	// cout << critic_character << endl;
	print_sequence(critic_character);
	truncated_find_last_character(critic_character);
	// cout << remaining_position.size();
	int remaining_num = find_min_num_to_cover(critic_character);
	rep(i, 0, remaining_num){
		cout << (char)(critic_character + 'a');
	}
	cout << endl;


	
	return 0;
}