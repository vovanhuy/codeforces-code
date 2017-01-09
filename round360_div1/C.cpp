
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




int main(){
	int n, k; cin >> n >> k;
	int c[n];
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}

	bool old_table[k+1][k+1];
	for(int x = 0; x <= k; x++){
		for(int y = 0; y <= k; y++){
			old_table[x][y] = false;
		}
	}
	old_table[0][0] = true;

	bool new_table[k+1][k+1];

	for(int i = 0; i < n; i++){
		for(int x = 0; x <= k; x++){
			for(int y = 0; y <= k; y++){
				// if(x > y) new_table[x][y] = false;
				// else{
					if(old_table[x][y]) new_table[x][y] = true;
					else if(y >= c[i] && old_table[x][y-c[i]]) new_table[x][y] = true;
					else if(x >= c[i] && y >= c[i] && old_table[x-c[i]][y-c[i]]) new_table[x][y] = true;
					else new_table[x][y] = false;
					// }
			}
		}

		for(int x = 0; x <= k; x++){
			for(int y = 0; y <= k; y++){
				old_table[x][y] = new_table[x][y];
			}
		}
	}

	vector<int> result;
	for(int i = 0; i <= k; i++){
		if(old_table[i][k]) result.push_back(i);
	}
	cout << result.size() << endl;
	for(int i = 0; i < result.size(); i++){
		cout << result[i];
		if(i == result.size() -1) cout << endl;
		else cout << " ";
	}

	
	
	return 0;

}
