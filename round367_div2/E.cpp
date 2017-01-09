
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




int main(){
	clock_t tStart = clock();
	int n, m, q; cin >> n >> m >> q;
	PII change[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			change[i][j] = PII(0, 0);
		}
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cout << "(" << change[i][j].first << " " << change[i][j].second << ")";
	// 	}
	// 	cout << endl;
	// }


	int initial_matrix[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &initial_matrix[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		display(initial_matrix[i], m);
	}

	for(int i = 0; i < q; i++){
		int a, b, c, d, h, w;
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &h, &w);
		a--; b--; c--; d--;
		for(int row = a; row < a + h; row++){
			change[row][b] = PII(change[row][b].first + c-a, change[row][b].second + d-b);
			if(b + w < m) change[row][b+w] = PII(change[row][b+w].first + a-c, change[row][b+w].second + b-d);
		}

		for(int row = c; row < c + h; row++){
			change[row][d] = PII(change[row][d].first + a-c, change[row][d].second + b-d);
			if(d + w < m) change[row][d+w] = PII(change[row][d+w].first + c-a, change[row][d+w].second + d-b);
		}

	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cout << "(" << change[i][j].first << " " << change[i][j].second << ")";
	// 	}
	// 	cout << endl;
	// }


	int final_matrix[n][m];
	for(int i = 0; i < n; i++){
		PII pre_sum = PII(0, 0);
		for(int j = 0; j < m; j++){
			pre_sum = PII(pre_sum.first + change[i][j].first, pre_sum.second + change[i][j].second);
			final_matrix[i+pre_sum.first][j+pre_sum.second] = initial_matrix[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0;j < m; j++){
			cout << final_matrix[i][j];
			if(j == m - 1) cout << endl;
			else cout << " ";
		}
	}
















    /* Do your stuff here */
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;

}
