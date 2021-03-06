/*
ID: vovanhu1
PROG: fracdec
LANG: C++
*/

#include <iostream>
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

void display(const vector<int>& a){
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
	int n, m, q;
	cin>>n>>m>>q;
	map<PII, PII> position;
	int fill[n][m];
	for(int i = 0; i < n; i++) initialise(fill[i], 1000000010, m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			position.insert(pair<PII, PII>(PII(i,j), PII(i, j)));
		}
	}


	for(int line = 0; line < q; line++){
		int type; cin>>type;
		if(type == 1){
			int row; cin>>row;
			row--;
			PII temp = position[PII(row, 0)];
			for(int j = 0; j < m - 1; j++){
				position[PII(row, j)] = position[PII(row, j+1)];
			}
			position[PII(row, m-1)] = temp;
		}
		else if(type == 2){
			int col; cin>>col;
			col--;
			PII temp = position[PII(0, col)];
			for(int i = 0; i < n - 1; i++){
				position[PII(i, col)] = position[PII(i+1, col)];
			}
			position[PII(n-1, col)] = temp;
		}
		else{
			int row, col, x;
			cin>>row>>col>>x;
			row--;
			col--;
			fill[position[PII(row, col)].first][position[PII(row, col)].second] = x;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(fill[i][j] < 1000000010){
				cout<<fill[i][j];
			}
			else{
				cout<<0;
			}
			if(j == m - 1) cout<<endl;
			else cout<<" ";
		}
	}

	return 0;

}
