/*
ID: vovanhu1
PROG: holstein
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
//#include <unordered_map>



using namespace std;

typedef pair<int, int> PII;

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
	int n, m; cin>>n>>m;

	PII left[n];
	PII right[n];
	for(int i = 0; i < n; i++){
		left[i].first = left[i].second = 0;
		right[i].first = right[i].second = 0;
	}

	for(int i = 0; i < n; i ++){
		if(2*i + 1 <= m) left[i].first = 2*i+1;
		if(2*i + 2 <= m) right[i].first = 2*i + 2; 
	}

	for(int i = 0; i < n; i++){
		if(2*i + 1 + 2*n <= m) left[i].second = 2*i + 1 + 2*n;
		if(2 *i + 2 + 2*n <= m) right[i].second = 2*i + 2 + 2*n;
	}

	for(int i = 0; i < n; i++){
		if(left[i].second != 0) cout<<left[i].second<<" ";
		if(left[i].first != 0) cout<<left[i].first<<" ";
		if(right[i].second != 0) cout<<right[i].second<<" ";
		if(right[i].first != 0) cout<<right[i].first<<" ";
	}
	


	
	return 0;

}