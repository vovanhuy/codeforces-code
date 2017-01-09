/*
ID: vovanhu1
PROG: fracdec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <list>
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

void display(const vector<int>& a){
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

typedef pair<PII, PII> PIIII;

struct comp{
	bool operator()(PIIII a, PIIII b){
		return a.first.second < b.first.second;
	}
};

int main(){
	int n; cin>>n;
	multiset<int> multi;
	set<PIIII, comp> queries;
	// vector<int> timeQuery;
	int count = 0;
	for(int line = 0; line < n; line++){
		int a, t, x;
		scanf("%d%d%d\n", &a, &t, &x);
		// cout<<a<<" "<<t<<" "<<x<<endl;
		if(a == 3){
			queries.insert(PIIII(PII(a, t), PII(x, count)));
			count++;	
		}
		else queries.insert(PIIII(PII(a,t), PII(x, -1)));
	}

	int res[count];
	// cout<<endl;

	for(set<PIIII>::iterator it = queries.begin(); it != queries.end(); it++){
		// cout<<it->first.first<<" "<<it->first.second<<" "<<it->second.first<<endl;
		int type = it->first.first;
		if(type == 1){
			multi.insert(it->second.first);
		}
		else if(type == 2){
			multiset<int>::iterator iter = multi.find(it->second.first);
			multi.erase(iter);
		}
		else{
			res[it->second.second] = multi.count(it->second.first);
		}
	}

	for(int i = 0; i < count; i++){
		cout<<res[i]<<endl;
	}



	return 0;

}
