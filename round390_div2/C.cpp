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
bool is_valid(char c){
	return !(c=='.' || c=='?' || c=='!' || c==',' || c==' ');
}
bool contain(string a, string b){
	int found = a.find(b);
	if(found != std::string::npos){
		if((found == 0 || !is_valid(a[found-1])) &&(found + b.size() == a.size() || !is_valid(a[found+b.size()]))){
			return true;
		}
		else{
			if(found == a.size() - 1) return false;
			else return contain(a.substr(found+1, a.size() - found -1), b);
		}
	}
	else return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	rep(test, 0, t){
		int n; cin >> n;
		vector<string> names(n);
		map<string, int> my_map;
		rep(i, 0, n){
			cin >> names[i];
			// cout << names[i] << endl;
			my_map[names[i]] = i;
		}

		int m; cin >> m;
		bool ok[m][n];
		string res[m];
		rep(i, 0, m) res[i] = "";
		rep(i, 0, m){
			rep(j, 0, n) ok[i][j] = true;
		}
		string text[m];
		bool valid = true;
		rep(i, 0, m){
			string messages="";
			while(messages.size() == 0){
				getline(cin, messages);
			}
			// cout << messages << endl;
			int haicham = messages.find(":");
			if(messages[0] != '?'){
				res[i] = messages.substr(0, haicham);
				rep(j, 0, n){
					ok[i][j] = false;
				}
				ok[i][my_map[res[i]]] = true;
				// cout << res[i] << endl;
			}

			messages = messages.substr(haicham+1, messages.size() - haicham-1);
			if(res[i].size() != 0 && contain(messages, res[i])) valid = false;
			text[i] = messages;
			// cout << messages << endl;
			rep(j, 0, n){
				if(contain(messages, names[j])){
					// cout << found << endl;
					ok[i][my_map[names[j]]] = false;
				}
			}
		}

		
		bool codinh[m];
		memset_array(codinh, false, m);
		rep(i, 0, m){
			if(res[i].size() != 0) codinh[i] = true;
			if(res[i].size() != 0 && !ok[i][my_map[res[i]]]){
				valid = false;
			}
		}
		if(!valid){
			cout << "Impossible" << endl;
			continue;
		}

		vector<string> ans[m];
		rep(i, 0, m){
			if(res[i].size() == 0){
				rep(j, 0, n){
					if(ok[i][j]) ans[i].pb(names[j]);
				}
			}
		}

		rep(i, 0, m){
			if(!codinh[i]){
				if(ans[i].size() == 0) valid = false;
				else res[i] = ans[i][0];
			}
		}
		rep(i, 0, m){
			if(res[i].size() == 0) valid = false;
		}
		if(!valid){
			cout << "Impossible" << endl;
			continue;
		}

		int pos[m];
		memset_array(pos, 0, m);

		while(true){
			bool change = false;
			rep(i, 0, m-1){
				if(my_map[res[i]] == my_map[res[i+1]]){
					if(codinh[i] || pos[i] == ans[i].size() - 1){
						if(codinh[i+1] || pos[i+1] == ans[i+1].size() - 1) valid = false;
						else res[i+1] = ans[i+1][++pos[i+1]];
					}
					else res[i] = ans[i][++pos[i]];
					change = true;
					break;
				}
			}
			if(!valid || !change) break;
		}

		if(!valid){
			cout << "Impossible" << endl;
			continue;
		}
		else rep(i, 0, m) cout << res[i] << ":" << text[i] << endl;


		
	}

	return 0;
}