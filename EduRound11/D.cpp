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
#include <map>
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

bool compar(PLL a, PLL b){
	if(a.first * b.second != a.second * b.first) {
		return a.first * b.second < a.second * b.first;
	}
	else return a.first*a.first + a.second*a.second < b.first*b.first +
		b.second*b.second;
}

int main(){
	int n; cin>>n;
	PLL point[n];
	for(int i = 0; i < n; i++){
		cin>>point[i].first;
		cin>>point[i].second;
	}

	bool(*com)(PLL, PLL) = compar;
	multimap<PLL, int, bool(*)(PLL, PLL)> ensemble(com);

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			long long x = point[i].first - point[j].first;
			long long y = point[i].second - point[j].second;
			if(y < 0){
				x = - x;
				y = -y;
			}
			if(y == 0){
				if(x < 0) x = -x;
			}
			
			if(ensemble.find(PLL(x, y)) != ensemble.end()){
				ensemble.find(PLL(x, y))->second++;
			}
			else{
				ensemble.insert(pair<PLL, int>(PLL(x,y), 1));
			}
			
		}
	}

	vector<long long> final;
	for(auto it = ensemble.begin(); it != ensemble.end(); ++it){
		if(it->second > 1) final.push_back(it->second);
	}

	long long sum = 0;

	//cout<<final.size()<<endl;

	for(int i = 0; i < final.size(); i++){
			sum += (final[i]*(final[i]-1))/2;
	}

	// ensemble.insert(pair<PLL, int>(PLL(2,3), 1));
	// // ensemble.insert(pair<PLL, int>(PLL(4,6), 1));
	// if(ensemble.find(PLL(2, 3)) != ensemble.end()){
	// 	cout<<"found"<<endl;
	// 	ensemble.find(PLL(2, 3))->second++;
	// 	cout<<ensemble.find(PLL(2, 3))->second<<endl;
	// } 

	cout<<(sum/2)<<endl;

	
	return 0;

}