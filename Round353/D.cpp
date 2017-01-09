
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <assert.h>
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

struct compareString
{
	bool operator()(string a, string b){
		for(int i = 0; i < min(a.length(), b.length()); i++){
			if(a[i] != b[i]) return a[i] < b[i];
		}
		return a.length() < b.length();
	}
};

struct comparePIIPriorFirst
{
	bool operator()(PII a, PII b){
		if(a.first != b.first) a.first < b.first;
		return a.second < b.second;
	}
};

struct comparePIIIPriorFirst
{
	bool operator()(pair<PII, int> a, pair<PII, int> b){
		return a.first.first < b.first.first;
	}
};




int main(){
	// clock_t tStart = clock();

	int n; cin>>n;
	int num[n];
	for(int i = 0; i < n; i++){
		cin>>num[i];
	}

	int level[n];
	int parent[n];

	level[0] = 0;
	parent[0] = 0;

	set<pair<PII, int>, comparePIIIPriorFirst> current;
	current.insert(pair<PII, int>(PII(num[0], 0), 0)); //value - level - index
	for(int i = 1; i < n; i++){
		set<pair<PII, int> >::iterator it = current.lower_bound(pair<PII, int>(PII(num[i], 0), 0));
		if(it == current.end()){
			it--;
			parent[i] = it->second;
			level[i] = it->first.second + 1;
			current.insert(pair<PII, int>(PII(num[i], level[i]), i));
		}
		else if(it == current.begin()){
			parent[i] = it->second;
			level[i] = it->first.second + 1;
			current.insert(pair<PII, int>(PII(num[i], level[i]), i));
		}
		else{
			set<pair<PII, int> >::iterator after = it;
			it--;
			if(it->first.second > after->first.second){
				parent[i] = it->second;
				level[i] = it->first.second + 1;
				current.insert(pair<PII, int>(PII(num[i], level[i]), i));		
			}
			else{
				parent[i] = after->second;
				level[i] = after->first.second + 1;
				current.insert(pair<PII, int>(PII(num[i], level[i]), i));	
			}
		}
	}

	for(int i = 1; i < n; i++){
		cout<<num[parent[i]];
		if(i == n - 1) cout<<endl;
		else cout<<" ";
	}
	

	// printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;

}
