
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

template<typename T>
void factor(int a[], int base, T num, int n){
	for(int i = n - 1; i >= 0; i--){
		a[i] = num % base;
		num = num/base;
	}
}

template<typename T>
int findLength(T n, int base){
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

long long find_remainder(long long base, long long power, long long modul){
	int length = findLength(power, 2);
	int bin[length];
	factor(bin, 2, power, length);
	long long remainder_list[length];
	remainder_list[0] = base;
	for(int i = 1; i < length; i++){
		remainder_list[i] = (remainder_list[i-1] * remainder_list[i-1]) % modul;
	}

	long long result = 1;
	for(int i = length - 1; i >= 0; i--){
		if(bin[i] == 1){
			result = (result * remainder_list[length - i - 1]) % modul;
		}
	}
	return result;
}


int main(){
	long long modul = (long long)(1e9+7);
	int k; cin >> k;
	long long a[k];
	for(int i = 0; i < k; i++){
		cin >> a[i];
	}

	// cout << find_remainder(30, 1e9 + 7) << endl;
	// find_remainder(n, 1e9+7)
	long long rm = 2;
	bool even = false;
	bool equal_to_one = true;
	for(int i = 0; i  < k; i++){
		if(a[i] % 2 == 0) even = true;
		if(a[i] != 1) equal_to_one = false;
		rm = find_remainder(rm, a[i], modul);
	}
	// cout << rm << endl;
	if(equal_to_one){
		cout << 0 << "/" << 1 << endl;
		return 0;
	}

	if(!even){
		long long tuso, mauso;

		if(rm % 2 == 0) mauso = rm/2;
		else mauso = (rm + modul) / 2;

		if((rm-2) % 6 == 0) tuso = (rm-2) /6;
		else if((rm - 2 + modul) % 6 == 0) tuso = (rm - 2 + modul)/6;
		else if((rm - 2 + modul*2) % 6 == 0) tuso = (rm - 2 + modul*2)/6;
		else if((rm - 2 + modul*3) % 6 == 0) tuso = (rm - 2 + modul*3)/6;
		else if((rm - 2 + modul*4) % 6 == 0) tuso = (rm - 2 + modul*4)/6;
		else tuso = (rm - 2 + 5 * modul)/6;


		cout << tuso << "/" << mauso << endl;

	}
	else{
		long long tuso, mauso;

		if(rm % 2 == 0) mauso = rm/2;
		else mauso = (rm + modul) / 2;

		if((rm+2) % 6 == 0) tuso = (rm+2) /6;
		else if((rm + 2 + modul) % 6 == 0) tuso = (rm + 2 + modul)/6;
		else if((rm + 2 + modul*2) % 6 == 0) tuso = (rm + 2 + modul*2)/6;
		else if((rm + 2 + modul*3) % 6 == 0) tuso = (rm + 2 + modul*3)/6;
		else if((rm + 2 + modul*4) % 6 == 0) tuso = (rm + 2 + modul*4)/6;
		else tuso = (rm + 2 + 5 * modul)/6;


		cout << tuso << "/" << mauso << endl;
	}


	
	return 0;

}
