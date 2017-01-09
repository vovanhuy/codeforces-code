
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

PLL solve(long long m){
	if(m < 8) return PII(m, m);
	else if(m < 14) return PLL(7, 7);
	else if(m < 15) return PLL(7, 14);
	else if(m < 22) return PLL(8, 15);
	else if(m < 23) return PLL(8, 22);
	else if(m < 42) return PLL(9, 23);
	else if(m < 49) return PLL(9, 42);
	else if(m < 50) return PLL(9, 49);
	else if(m < 64) return PLL(10, 50);
	else{
		long long cube = (long long) pow(m, 1/3.0);
		if(cube*cube*cube == m) return solve(m-1);
		else{
			PLL temp1 = solve(m - cube*cube*cube);
			temp1.first += 1;
			temp1.second += cube*cube*cube;
			PLL temp2 = solve(cube*cube*cube-1);
			if(temp1.first > temp2.first) return temp1;
			else if(temp1.first == temp2.first){
				if(temp1.second > temp2.second)  return temp1;
				else return temp2;
			}
			else return temp2;
		}
	}  
}


int main(){
	long long m; cin >> m;
	PLL a = solve(m);
	cout << a.first << " " << a.second << endl;
	
	return 0;

}
