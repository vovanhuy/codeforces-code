

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
#include <ctime>
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

struct comp
{
	bool operator()(PII a, PII b){
		if(a.second != b.second) return a.second > b.second;
		return a.first < b.first;
	}
};

int main(){
	// clock_t tStart = clock();
	
	
	int n; cin>>n;
	int color[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &color[i]);
	}
	int count[n+1];
	initialise(count, 0, n+1);
	for(int i = 0; i < n; i++){
		int trace[n+1];
		initialise(trace, 0, n+1);
		// set<PII, comp> curr;
		list<PII>curr;
		for(int j = i; j < n; j++){
			trace[color[j]]++;
			if(curr.size() == 0){
				curr.push_front(PII(color[j], trace[color[j]]));
				count[curr.begin()->first]++;
			}
			else{
				if(trace[color[j]] > curr.begin()->second){
					if(color[j] == curr.begin()->first){
						curr.begin()->second++;
					}
					else{
						curr.push_front(PII(color[j], trace[color[j]]));
					}
				}
				else if(trace[color[j]] == curr.begin()->second){
					if(color[j] < curr.begin()->first){
						curr.push_front(PII(color[j], trace[color[j]]));	
					}
				}
				count[curr.begin()->first]++;
			}
			// if(trace[color[j]] == 0){
			// 	trace[color[j]] = 1;
			// 	curr.insert(PII(color[j], 1));
			// 	count[curr.begin()->first]++;
			// }
			// else{
			// 	curr.erase(PII(color[j], trace[color[j]]));
			// 	trace[color[j]]++;
			// 	curr.insert(PII(color[j], trace[color[j]]));
			// 	count[curr.begin()->first]++;
			// }
		}	
	}
	for(int i = 1; i <= n; i++){
		printf("%d", count[i]);
		if(i != n) printf(" ");
		else printf("\n");
	}
	
		// the code you wish to time goes here
	// printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


	return 0;

}
