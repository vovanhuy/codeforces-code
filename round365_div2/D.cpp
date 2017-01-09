
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
#include <assert.h>
//#include <unordered_map>



using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
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

struct compPIII
{
	bool operator()(PIII a, PIII b){
		if(b.first.second != a.first.second) return a.first.second < b.first.second;
		return a.first.first > b.first.first;
	}
} compPIII_obj;


int BIT[1000000 + 5];
int n; 

void init(){
	for(int i = 0; i <= n; i++){
		BIT[i] = 0;
	}
}

int prefixSum(int idx){
	int sum = 0;
	while(idx > 0){
		sum ^= BIT[idx];
		idx -= (idx & -idx);
	}

	return sum;
}

int intervalSum(int a, int b){
	return prefixSum(b) ^ prefixSum(a-1);
}


void update(int idx, int val){
	assert(idx > 0);
	while(idx <= n){
		BIT[idx] ^= val;
		idx += (idx & -idx);
	}
}


// use BIT tree offline
int main(){
	cin >> n;
	int a[n];
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int m; cin >> m;
	PIII querry[m];
	for(int i = 0; i < m; i++){
		scanf("%d %d", &querry[i].first.first, &querry[i].first.second);
		querry[i].second = i;
	}

	int prefix_odd[n+1];
	prefix_odd[0] = 0;
	for(int i = 1; i <= n; i++){
		prefix_odd[i] = prefix_odd[i-1] ^ a[i];
	}

	sort(querry, querry+m, compPIII_obj);


	map<int, int> lastSeen;
	init();

	int result[m];

	int currentPos = 0;
	for(int i = 0; i < m; i++){
		int l = querry[i].first.first;
		int r = querry[i].first.second;

		if(r > currentPos){
			while(currentPos < r){
				currentPos++;
				if(lastSeen.find(a[currentPos]) == lastSeen.end()){
					lastSeen[a[currentPos]] = currentPos;
					update(currentPos, a[currentPos]);
				}
				else{
					update(lastSeen[a[currentPos]], a[currentPos]);
					update(currentPos, a[currentPos]);
					lastSeen[a[currentPos]] = currentPos;
				}
			}

			result[querry[i].second] = intervalSum(l, r) ^ prefix_odd[l-1] ^ prefix_odd[r];
			
		}
		else{
			result[querry[i].second] = intervalSum(l, r) ^ prefix_odd[l-1] ^ prefix_odd[r];
		}
	}
	for(int i = 0; i < m; i++){
		printf("%d\n", result[i]);
	}

	return 0;

}
