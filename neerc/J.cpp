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
#include <tuple>
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



/////////////////////////////////////////////////////////////////////////////
// NEVER USE NAME : DISTANCE FOR FUNCTION
////////////////////////////////////////////////////////////////////////////
// compare_lexical_string("huy", "huy") will return false
bool cmp_bottle(pii a, pii b){
	if(a.sn != b.sn) return a.sn > b.sn;
	return a.fi > b.fi;
}

// map<tuple<int, int, int>, int> dp;
vector<pii> bottle(100);
int partial_capacity[100];
int partial_soda[100];
int dp[101][10001][101];


// int solve(int i, int j, int k){
// 	if(dp.find(make_tuple(i, j, k)) != dp.end()) return dp[make_tuple(i, j, k)];
// 	//

// 	if(i == 0 && j == 0 && k == 0){
// 		dp[make_tuple(0, 0, 0)] = 0;
// 		return 0;
// 	}
// 	//
// 	if(i == 0 && (j != 0 || k != 0)){
// 		dp[make_tuple(i, j, k)] = -1;
// 		return -1;
// 	}
// 	//
// 	if(k > i){
// 		dp[make_tuple(i, j, k)] = -1;
// 		return -1;
// 	} 

// 	//
// 	if(k == i){
// 		if(partial_capacity[i-1] >= j){
// 			dp[make_tuple(i, j, k)] = partial_soda[i-1];
// 			return partial_soda[i-1];
// 		}
// 		else{
// 			dp[make_tuple(i, j, k)] = -1;
// 			return -1;
// 		}
// 	}

// 	if(k < i){
// 		if(k == 0 && j == 0){
// 			dp[make_tuple(i, j, k)] = 0;
// 			return 0;
// 		}
// 		if(k == 0 && j > 0){
// 			dp[make_tuple(i, j, k)] = -1;
// 			return -1;
// 		}

// 		int first_case;
// 		int res = solve(i-1, max(0, j-bottle[i-1].sn), k-1);
// 		if(res == -1){
// 			first_case = -1;
// 		}
// 		else first_case = bottle[i-1].fi + res;

// 		res = solve(i-1, j, k);
// 		if(first_case != -1){
// 			dp[make_tuple(i, j, k)] = max(first_case, res);
// 			return max(first_case, res);
// 		}
// 		else{
// 			dp[make_tuple(i, j, k)] = res;
// 			return res;
// 		}
// 	}


// }

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	
	rep(i, 0, n) cin >> bottle[i].fi;
	rep(i, 0, n) cin >> bottle[i].sn;
	sort(bottle.begin(), bottle.end(), cmp_bottle);

	int soda = 0;
	rep(i , 0, n) soda += bottle[i].fi;

	// cout << soda << endl;

	int num_of_bottle = 0;
	int part_sum = 0;
	rep(i, 0, n){

		part_sum += bottle[i].sn;
		// cout << part_sum << endl;
		if(part_sum >= soda){
			num_of_bottle = i+1;
			break;
		}
	}
	
	partial_capacity[0] = bottle[0].sn;
	partial_soda[0] = bottle[0].fi;
	rep(i, 1, n){
		partial_capacity[i] = partial_capacity[i-1] + bottle[i].sn;
		partial_soda[i] = partial_soda[i-1] + bottle[i].fi;
	}

	
	// dp[i][j][k] = the maximum amount of soda
	// that a set of k bottles in [1..i]
	// whose total capacities are at least j contains

	rep(j, 0, soda+1){
		rep(k, 0, num_of_bottle+1) dp[0][j][k] = -1;
	}
	dp[0][0][0] = 0;

	rep(i, 1, n+1){
		// bottle from 0 to i-1
		rep(j, 0, soda+1){
			rep(k, 0, num_of_bottle+1){
				if(k > i){
					dp[i][j][k] = -1;
					continue;
				}
				if(k == i){
					if(partial_capacity[i-1] >= j)
						dp[i][j][k] = partial_soda[i-1];
					else dp[i][j][k] = -1;
					continue;
				}

				if(k < i){
					if(k == 0 && j == 0){
						dp[i][j][k] = 0;
						continue;
					}
					if(k == 0 && j > 0){
						dp[i][j][k] = -1;
						continue;
					}

					int first_case;
					if(dp[i-1][max(0, j-bottle[i-1].sn)][k-1] == -1){
						first_case = -1;
					}
					else first_case = bottle[i-1].fi + dp[i-1][max(0, j-bottle[i-1].sn)][k-1];

					if(first_case != -1){
						dp[i][j][k] = max(first_case, dp[i-1][j][k]);
					}
					else dp[i][j][k] = dp[i-1][j][k];
				}


			}
		}
	}

	// cout << dp[n][soda][num_of_bottle] << endl;
	// int res = solve(n, soda, num_of_bottle);




	cout << num_of_bottle << " " << soda - dp[n][soda][num_of_bottle] << endl;
	
	return 0;
}