
#include <iostream>
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
//#include <unordered_map>



using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;

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

void display(vector<int> a){
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




int main(){
	int n, m; cin >> n >> m;
	list<int> son[n];
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		son[u-1].push_back(v-1);
		son[v-1].push_back(u-1);
	}

	int side[n];
	initialise(side, -1, n);
	for(int i = 0; i < n; i++){
		if(side[i] != -1) continue;

		queue<int> q;
		q.push(i);
		side[i] = 0;
		while(!q.empty()){
			int current = q.front(); q.pop();
			for(auto fil : son[current]){
				if(side[fil] == -1){
					side[fil] = 1 - side[current];
					q.push(fil);
				}
				else if(side[fil] == side[current]){
					cout << -1 << endl;
					return 0;
				}
				else continue;
			}
		}
	}

	vector<int> zero;
	vector<int> one;
	for(int i = 0; i < n; i++){
		if(side[i] == 0) zero.push_back(i+1);
		else one.push_back(i+1);
	}
	cout << zero.size() << endl;
	for(int i = 0; i < zero.size(); i++){
		cout << zero[i];
		if(i == zero.size() - 1) cout << endl;
		else cout << " ";
	}
	cout << one.size() << endl;
	for(int i = 0; i < one.size(); i++){
		cout << one[i];
		if(i == one.size() - 1) cout << endl;
		else cout << " ";
	}


	
	
	return 0;

}
