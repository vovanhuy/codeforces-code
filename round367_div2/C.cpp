
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

bool compareString(string a, string b){
	for(int i = 0; i < min(a.length(), b.length()); i++){
		if(a[i] < b[i]) return true;
		else if(a[i] > b[i]) return false;
	}

	if(a.length() <= b.length()) return true;
	else return false;
}

string reverseString(string a){
	string b = a;
	for(int i = 0; i < a.length(); i++){
		b[i] = a[a.length() - i - 1];
	}
	return b;
}


int main(){
	 clock_t tStart = clock();
	 int n;  cin >> n;
	 long long c[n];
	 for(int i = 0; i < n; i++){
	 	scanf("%llu", &c[i]);
	 }
	 string s[n];
	 for(int i = 0; i < n; i++){
	 	cin >> s[i];
	 }

	 long long dp[n][2];
	 //dp[i][0] no reverse
	 dp[0][0] = 0;
	 dp[0][1] = c[0];
	 for(int i = 1; i < n; i++){
	 	dp[i][0] = dp[i][1] = std::numeric_limits<long long>::max();

	 	dp[i][0] = dp[i-1][0] != -1 && compareString(s[i-1], s[i]) ? min(dp[i][0], dp[i-1][0]) : dp[i][0];
	 	dp[i][0] = dp[i-1][1] != -1 && compareString(reverseString(s[i-1]), s[i]) ? min(dp[i][0], dp[i-1][1]) : dp[i][0];

	 	dp[i][1] = dp[i-1][0] != -1 && compareString(s[i-1], reverseString(s[i])) ? min(dp[i][1], dp[i-1][0] + c[i]) : dp[i][1];
	 	dp[i][1] = dp[i-1][1] != -1 && compareString(reverseString(s[i-1]), reverseString(s[i])) ? min(dp[i][1], dp[i-1][1] + c[i]) : dp[i][1];

	 	if(dp[i][0] == std::numeric_limits<long long>::max()) dp[i][0] = -1;
	 	if(dp[i][1] == std::numeric_limits<long long>::max()) dp[i][1] = -1;
	 }

	 if(dp[n-1][0] != -1 && dp[n-1][1] != -1){
	 	cout << min(dp[n-1][0], dp[n-1][1]) << endl;
	 }
	 else if(dp[n-1][0] != -1) cout << dp[n-1][0] << endl;
	 else cout << dp[n-1][1] << endl;
	 // // string a = "huy";
	 // // cout << reverseString(a) << " " << a << endl;


	 // cout << 100000 << endl;
	 // for(int i = 0; i < 100000; i++){
	 // 	cout << 20 << endl;
	 // }
	 // for(int i = 0; i < 100000; i++){
	 // 	cout << "huy" << endl;
	 // }
	 






    // /* Do your stuff here */
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;

}
