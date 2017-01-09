 
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

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<double, double> PDD;

//#define MIN = -1000000000;
template<typename T>
void display(T a[], int size){
	for(int i = 0; i < size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void display(vector<PII> a){
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


bool compare(PII a, PII b){
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

struct comp
{
	bool operator()(vector<PII> a, vector<PII> b){
		return a.size() < b.size();
	}
}compObj;




int main(){
	 ios_base::sync_with_stdio(0); cin.tie(0);
	 int n, m , k; cin >> n >> m >> k;
	 string graph[n];
	 for(int i = 0; i < n; i++){
	 	cin >> graph[i];
	 }

	 vector< vector<PII> > cluster_size;
	 bool trace[n][m];
	 for(int i = 0; i < n; i++){
	 	for(int j = 0; j < m; j++){
	 		trace[i][j] = false;
	 	}
	 }

	 for(int i = 0; i < n; i++){
	 	for(int j = 0; j < m; j++){
	 		if(trace[i][j] || graph[i][j] == '*') continue;

	 		queue<PII> q;
	 		q.push(PII(i, j));
	 		trace[i][j] = true;
	 		bool adj_to_sea = false;
	 		vector<PII> count;

	 		while(!q.empty()){
	 			PII current = q.front(); q.pop();
	 			count.push_back(current);
	 			int x = current.first;
	 			int y = current.second;
	 			if(x == 0 || x == n - 1 || y == 0 || y == m -1) adj_to_sea = true;
	 			if(x-1 >= 0 && graph[x-1][y] == '.' && !trace[x-1][y]){
	 				q.push(PII(x-1, y));
	 				trace[x-1][y] = true;
	 			}
	 			if(x + 1 < n && graph[x+1][y] == '.' && !trace[x+1][y]){
	 				q.push(PII(x+1, y));
	 				trace[x+1][y] = true;
	 			}
	 			if(y - 1 >= 0 && graph[x][y-1] == '.' && !trace[x][y-1]){
	 				q.push(PII(x, y-1));
	 				trace[x][y-1] = true;
	 			}
	 			if(y+1 < m && graph[x][y+1] =='.' && !trace[x][y+1]){
	 				q.push(PII(x, y+1));
	 				trace[x][y+1] = true;
	 			}
	 		}

	 		if(!adj_to_sea) cluster_size.push_back(count);
	 	}
	 }

	 sort(cluster_size.begin(), cluster_size.end(), compObj);

	 // for(int i = 0; i < cluster_size.size(); i++){
	 // 	cout << cluster_size[i] << endl;
	 // }
	 // for(int i = 0; i < n; i++){
	 // 	for(int j = 0; j < m; j++){
	 // 		cout << trace[i][j] << " ";
	 // 	}
	 // 	cout << endl;
	 // }

	 int res = 0;
	 for(int i = 0; i < cluster_size.size() - k; i++){
	 	res += cluster_size[i].size();
	 }

	 cout << res << endl;

	 for(int i = 0; i < cluster_size.size() - k; i++){
	 	for(int j = 0; j < cluster_size[i].size(); j++){
	 		graph[cluster_size[i][j].first][cluster_size[i][j].second] = '*';
	 	}
	 }

	 for(int i = 0; i < n; i++){
	 	cout << graph[i] << endl;
	 }
	return 0;

}
