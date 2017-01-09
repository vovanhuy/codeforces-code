

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

bool compare(vector<int> a, vector<int> b){
	for(int i = 0; i < a.size() - 1; i++){
		if(a[i] != b[i]) return a[i] < b[i];
	}
	return a[a.size()-1] < b[a.size()-1];
}


int main(){
	int n, k; cin>>n>>k;
	int a, b, c, d; cin>>a>>b>>c>>d;
	int trace[n+1];
	initialise(trace, 0, n+1);
	trace[a] = trace[b] = trace[c] = trace[d] = 1;
	if(n == 4){
		// if(k <= n-1){
			cout<<-1<<endl;
		// }
		// else{
		// 	cout<<a<<" "<<c<<" "<<d<<" "<<b<<endl;
		// 	cout<<c<<" "<<a<<" "<<b<<" "<<d<<endl;
		// }
	}
	else{
		if(k <= n){
			cout<<-1<<endl;
		}
		else{
			cout<<a<<" "<<c<<" ";
			for(int i = 1; i <= n; i++){
				if(trace[i] == 0) cout<<i<<" ";
			}
			cout<<d<<" "<<b<<endl;

			cout<<c<<" "<<a<<" ";
			for(int i = 1; i <= n; i++){
				if(trace[i] == 0) cout<<i<<" ";
			}
			cout<<b<<" "<<d<<endl;
		}
	}
	
	
	return 0;

}
