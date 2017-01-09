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
	int n, q; //cin>>n>>q;
	scanf("%d%d\n", &n, &q);
	int zero = 0;
	int one = 1;
	for(int line = 0; line < q; line++){
		int type; //cin>>type;
		scanf("%d", &type);
		if(type == 1){
			int x; //cin>>x;
			scanf("%d\n", &x);
			zero = (zero + n + x) % n;
			one = (one + x + n) % n;
		}
		else{
			scanf("\n");
			if(zero % 2 == 0){
				zero++;
				one--;
			}
			else{
				one++;
				zero--;
			}
		}
	}

	// cout<<zero<<" "<<one<<endl;
	// zero++; one++;
	// int odd, even;
	
	// if(zero % 2 != 0){
	// 	if(zero == 1){
	// 		odd = 1;
	// 	}
	// }
	



	// for(int i = 1; i <= n/2; i++){
	// 	cout<<odd<<" "<<even;
	// 	odd = (odd + 2) % n;
	// 	if(even == n - 2) even = n;
	// 	else even = (even + 2) % n;
	// 	if(i == n/2) cout<<endl;
	// 	else cout<<" ";

	// }

	int pos[n + 1];
	int res[n+1];

	for(int i = 0; i < n; i++){
		if(i % 2 == 0){
			pos[i+1] = (zero+i)%n + 1;
		}
		else{
			pos[i+1] = (one - 1 + i) % n + 1;
		}
		// if(i == n - 1) cout<<endl;
		// else cout<<" ";
	}

	for(int i = 1; i <= n; i++){
		res[pos[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		printf("%d", res[i]);
		if(i == n) printf("\n");
		else printf(" ");
	}



	return 0;

}
