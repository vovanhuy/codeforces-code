
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
#include <queue>
#include <stack>
#include <time.h>
#include <assert.h>
//#include <unordered_map>



using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<double, double> PDD;

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

// int BIT[300000 + 5];
// int n, q; 

// void init(){
// 	for(int i = 0; i <= q; i++){
// 		BIT[i] = 0;
// 	}
// }

// inline int prefixSum(int idx){
// 	int sum = 0;
// 	while(idx > 0){
// 		sum += BIT[idx];
// 		idx -= (idx & -idx);
// 	}

// 	return sum;
// }

// inline int intervalSum(int a, int b){
// 	return prefixSum(b) - prefixSum(a-1);
// }


// inline void update(int idx, int val){
// 	assert(idx > 0);
// 	while(idx <= q){
// 		BIT[idx] += val;
// 		idx += (idx & -idx);
// 	}
// }


int main(){
	 clock_t tStart = clock();
	 // cin >> n >> q;
	 // int trace[q+1];
	 // int last_t = 0;
	 // //************************************
	 // list<int*> list_event[n+1];
	 // // for(int i = 0; i <=n; i++){
	 // // 	list_event[i].push_back(NULL);
	 // // }

	 // //
	 // list<int*>::iterator last_read[n+1];
	 // for(int i = 0; i <=n ; i++){
	 // 	last_read[i] = list_event[i].end();
	 // }
	 // ///**************************************
	 // int current_num_element = 0;
	 // init();
	 // for(int i = 1; i <= q; i++){

	 // 	int type; scanf("%d", &type);
	 // 	if(type == 1){
	 // 		int x; 
	 // 		scanf("%d", &x);
	 // 		current_num_element++;
	 // 		trace[current_num_element] = x;
	 // 		list_event[x].push_back(&trace[current_num_element]);
	 // 		update(current_num_element, 1);
	 // 		printf("%d\n", intervalSum(0, current_num_element));
	 // 		// cout << current_num_element << endl;
	 // 		// display(BIT, q+1);
	 // 	}
	 // 	if(type == 2){
	 // 		int x;
	 // 		scanf("%d", &x);
	 // 		list<int*>::iterator it = last_read[x];
	 // 		it++;
	 // 		while(it != list_event[x].end()){
	 // 			update(*(*it), -1);
	 // 			it++;
	 // 		}
	 // 		last_read[x] = --it;
	 // 		printf("%d\n", intervalSum(0, current_num_element));
	 // 		// cout << current_num_element << endl;
	 // 		// display(BIT, q+1);
	 // 	}
	 // 	if(type == 3){
	 // 		int t; scanf("%d", &t);
	 // 		for(int run = last_t+1; run <= t; run++){
	 // 			if(*(*last_read[trace[run]]) < run){
	 // 				update(run, -1);
	 // 				last_read[trace[run]]++;
	 // 			}
	 // 		}
	 // 		last_t = t;
	 // 		printf("%d\n", intervalSum(0, current_num_element));
	 // 		// cout << current_num_element << endl;
	 // 		// display(BIT, q+1);
	 // 	}
	 // }

	// int maxx = 300000;
	// cout << maxx << " " << maxx << endl;
	// int num = 1;
	// cout << 1 << " " << 1 << endl;

	// for(int i = 1; i < maxx; i++){
	// 	int type = rand() % 3 + 1;
	// 	cout << type << " " << rand() % min(30, num) + 1 << endl;
	// 	if(type == 1) num++;
	// }


	int n, q;
	cin >> n >> q;
	int count = 0;
	list<int> unread[n];
	int mark[q];
	int current_num_element = 0;
	int last_t = -1;
	for(int i = 0; i < q; i++){
		int type; scanf("%d", &type);
		if(type == 1){
			int x; scanf("%d", &x); x--;
			mark[current_num_element] = x;
			unread[x].push_back(current_num_element);
			current_num_element++;
			count++;
			printf("%d\n", count);
		}
		if(type == 2){
			int x; scanf("%d", &x); x--;
			count -= unread[x].size();
			unread[x].clear();
			printf("%d\n", count);
		}
		if(type == 3){
			int t; scanf("%d", &t); t--;
			for(int run = last_t+1; run <= t; run++){
				if(unread[mark[run]].size() != 0 && run == *unread[mark[run]].begin()){
					count--;
					unread[mark[run]].erase(unread[mark[run]].begin());
				}
			}
			if(last_t < t) last_t = t;
			printf("%d\n", count);
		}
	}

    // /* Do your stuff here */
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;

}
