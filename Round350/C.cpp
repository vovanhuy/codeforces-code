
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

struct comp
{
	bool operator()(pair<int, PII> a, pair<int, PII> b){
		if(a.second.first != b.second.first) return a.second.first > b.second.first;
		else return a.second.second > b.second.second;
	}
};


int main(){
	int n; cin>>n;
	int lang[n];
	for(int i = 0; i < n; i++) cin>>lang[i];
	int m; cin>>m;
	PII film[m];
	for(int i = 0; i < m; i++) cin>>film[i].first;
	for(int i = 0; i < m; i++) cin>>film[i].second;

	map<int, int> count;
	for(int i = 0; i < n; i++){
		if(count.find(lang[i]) == count.end()){
			count[lang[i]] = 1;
		}
		else count[lang[i]]++;
	}

	set<pair<int, PII>, comp> countLang;
	for(int i = 0; i < m; i++){
		int id = i+1;
		int vui = count.find(film[i].first) != count.end()? count[film[i].first] : 0;
		int thoaman = count.find(film[i].second) != count.end()? count[film[i].second] : 0;
		countLang.insert(pair<int, PII>(id, PII(vui, thoaman)));
	}

	cout<<countLang.begin()->first<<endl;

	




	
	
	return 0;

}
