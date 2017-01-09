 
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <time.h>
#include <assert.h>
//#include <unordered_map>



using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

#define MININT = numeric_limits<int>::min()
#define MAXINT = numeric_limits<int>::max()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)





template<typename T>
void display(T a[], int size){
	for(int i = 0; i < size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void display(vector<pii> a){
	for(int i = 0; i < a.size(); i++){
		cout<<"("<<a[i].first<<","<<a[i].second<<")"<<" ";
	}
	cout<<endl;
}

template<typename T>
void display(vector<T> a){
	for(int i = 0; i < a.size(); i++){
		cout<<a[i];
		if(i == a.size() - 1) cout<<endl;
		else cout<<" ";
	}
}

template<typename T>
void initialise(T a[], T value, int length){
        for(int i = 0; i < length; i++) a[i] = value;
}

template<typename T>
void initialise(vector<T>& a, T value){
    for(int i = 0; i < a.size(); i++) a[i] = value;
}


bool compare(pii a, pii b){
	if(a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

int max(int a[], int n){
	int max = -1000000000;
	for(int i = 0; i < n; i++){
		if(a[i] > max) max = a[i];
	}
	return max;
}

bool find(string a[], string s, int n){
	int left = 0;
	int right = n -1;
	while(left < right){
		int mid = (left+right)/2;
		if(s.compare(a[mid]) == 0) return true;
		else if(s.compare(a[mid]) < 0){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return false;
}

void factor(int a[], int base, int num, int n){
	for(int i = n - 1; i >= 0; i--){
		a[i] = num % base;
		num = num/base;
	}
}


int findLength(int n, int base){
	int i = 0;
	while(n > 0){
		i++;
		n = n/base;
	}
	return i;
}

int gcd(int a, int b){
	while( a % b != 0 && b % a != 0){
		if(b > a){
			b = b % a;
		}
		else if(a > b){
			a = a % b;
		}
	}

	if(a <= b) return a;
	else return b;
}




int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	list<int> graph[n];
	forn(i, m){
		int u, v; cin >> u >> v;
	 	u--; v--;
	 	graph[u].push_back(v);
	 	graph[v].push_back(u);
	}

	int s, t, ds, dt; cin >> s >> t >> ds >> dt;
	s--; t--;
	int component[n];
	forn(i, n) component[i] = -1;


	// find components if all edges from and to s are removed
	int num_of_component = 0;
	forn(i, n){
		if(component[i] == -1 && i != s && i != t){
			// cout << "i: " << i << endl;
			queue<int> q;
			q.push(i);
			component[i] = num_of_component;
			while(!q.empty()){
				int current = q.front(); q.pop();
				for(list<int>::iterator it = graph[current].begin(); 
					it != graph[current].end(); it++){
					if(*it != s && *it != t && component[*it] == -1){
						component[*it] = component[current];
						q.push(*it);
					}
				}
			}
			num_of_component++;
		}
	}

	// display(component, n);
	bool adj_s[num_of_component];
	bool adj_t[num_of_component];
	forn(i, num_of_component){
		adj_s[i] = adj_t[i] = false;
	}
	for(list<int>::iterator it = graph[s].begin(); it != graph[s].end(); it++){
		adj_s[component[*it]] = true;
	}
	for(list<int>::iterator it = graph[t].begin(); it != graph[t].end(); it++){
		adj_t[component[*it]] = true;
	}

	int only_s = 0, only_t = 0, s_and_t = 0;
	forn(i, num_of_component){
		if(adj_s[i] && !adj_t[i]) only_s++;
		if(!adj_s[i] && adj_t[i]) only_t++;
		if(adj_s[i] && adj_t[i]) s_and_t++;
	}

	bool valid = true;
	if(s_and_t == 0){
		if(only_s > ds-1 || only_t > dt-1) valid = false;
	}
	else{
		if(only_s > ds-1 || only_t > dt-1 || num_of_component-1 > ds+dt-2) valid = false;
	}

	if(!valid) cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		if(s_and_t == 0){
			cout << s+1 << " " << t+1 << endl;
			set<int> compo_s;
			set<int> compo_t;
			for(list<int>::iterator it = graph[s].begin(); it != graph[s].end(); it++){
				if(compo_s.find(component[*it]) == compo_s.end() && *it != t){
					cout << s+1 << " " << *it+1 << endl;
					compo_s.insert(component[*it]);
				}
			}
			for(list<int>::iterator it = graph[t].begin(); it != graph[t].end(); it++){
				if(compo_t.find(component[*it]) == compo_t.end() && *it != s){
					cout << t+1 << " " << *it+1 << endl;
					compo_t.insert(component[*it]);
				}
			}
		}
		else{
			set<int> compo_s;
			set<int> compo_t;
			// cout << "here" << endl;
			for(list<int>::iterator it = graph[s].begin(); it != graph[s].end(); it++){
				if(*it != t && compo_s.find(component[*it]) == compo_s.end() && adj_s[component[*it]] && !adj_t[component[*it]]){
					cout << s+1 << " " << *it+1 << endl;
					compo_s.insert(component[*it]);
				}
			}
			for(list<int>::iterator it = graph[t].begin(); it != graph[t].end(); it++){
				if(*it != s && compo_t.find(component[*it]) == compo_t.end() && !adj_s[component[*it]] && adj_t[component[*it]]){
					cout << t+1 << " " << *it+1 << endl;
					compo_t.insert(component[*it]);
				}
			}

			bool add_commun = false;

			for(list<int>::iterator it = graph[s].begin(); it != graph[s].end(); it++){
				// cout << *it << endl;
				if(*it != t && adj_s[component[*it]] && adj_t[component[*it]] && compo_s.size() < ds 
								&& compo_s.find(component[*it]) == compo_s.end()){
					
					cout << s+1 << " " << *it+1 << endl; 
					compo_s.insert(component[*it]);
				}
			}
			for(list<int>::iterator it = graph[t].begin(); it != graph[t].end(); it++){
				// cout << *it << endl;
				if(*it != s && adj_t[component[*it]] && adj_s[component[*it]] && compo_t.size() < dt 
								&& compo_t.find(component[*it]) == compo_t.end()){
					
					if(compo_s.find(component[*it]) != compo_s.end() && !add_commun){
						cout << t+1 << " " << *it+1 << endl; 
						compo_t.insert(component[*it]);
						add_commun = true;	
					}

					if(compo_s.find(component[*it]) == compo_s.end()){
						cout << t+1 << " " << *it+1 << endl; 
						compo_t.insert(component[*it]);
					}


					
				}
			}
		}

		bool added[n];
		forn(i, n) added[i] = false;
		added[s] = added[t] = true;
		forn(i, n){
			if(!added[i]){
				queue<int> q; q.push(i); added[i] = true;
				while(!q.empty()){
					int current = q.front(); q.pop();
					for(list<int>::iterator it = graph[current].begin(); it!= graph[current].end(); it++){
						if(!added[*it]){
							cout << current+1 << " " << *it+1 << endl;
							added[*it] = true;
							q.push(*it);
						}
					}
				}
			}
		}

	}


	return 0;

}
