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
#define forn(i, n) for(int i = 0; i < (n); i++)  
#define forab(i, a, b) for(int i = (a); i < (b); i++)





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
	 int a[n];
	 forn(i, n){
	 	cin >> a[i];
	 	a[i]--;
	 }

	 // display(a, n);

	 int count[m];
	 forn(i, m) count[i] = 0;
	 forn(i, n) if(a[i] < m) count[a[i]]++;
	 // display(count, m);
	 int min_val = n/m;
	 int res = 0;
	 queue<int> q;
	 forn(i, m){
	 	if(count[i] < min_val){
	 		res += min_val - count[i];
	 		// cout << min_val - count[i] << endl;
	 		forn(j, min_val - count[i]){
	 			q.push(i);	
	 		} 
	 	}
	 }

	 forn(i, n){
	 	// cout << "a[i]: " << a[i] << endl;
	 	if(!q.empty()){
	 		if(a[i] >= m){
		 		a[i] = q.front();
		 		q.pop();
		 	}
		 	else if(count[a[i]] > min_val){
		 		count[a[i]]--;
		 		a[i] = q.front();
		 		q.pop();
		 		
		 	}
	 	}
	 	// display(count, m);
	 }


	 cout << min_val << " " << res << endl;
	forn(i, n){
		cout << a[i] + 1;
		if(i == n -1) cout << endl;
		else cout << " ";
	}

	return 0;

}
