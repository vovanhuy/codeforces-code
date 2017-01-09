

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

struct comp
{
	bool operator()(string a, string b){
		for(int i = 0; i < min(a.length(), b.length()); i++){
			if(a[i] != b[i]) return a[i] < b[i];
		}
		return a.length() < b.length();
	}
};



int main(){
	char read[10001];
	scanf("%s", read);
	string s(read);
	// cout<<s<<endl;
	// cout<<s.length()<<endl;
	int len = s.length();
	set<string, comp> res;
	for(int i = 5; i < s.length(); i++){
		if(i + 2 == s.length() - 1){
			string two(s, i, 3);
			res.insert(two);	
		}
		else if(i + 2 < s.length() - 2){
			bool trace[len+1];
			trace[len] = true;
			trace[len-1] = false;
			trace[len-2] = true;
			for(int j = len - 3; j >= i + 3; j--){
				if(trace[j+2]) trace[j] = true;
				else{
					if(s[i] != s[j] || s[i+1] != s[j+1] || s[i+2] != s[j+2]){
						trace[j] = trace[j+3];
					}
				}
			}
			if(trace[i+3]) res.insert(string(s, i, 3));
		}



		if(i + 1 == s.length() - 1){
			string one(s, i, 2);
			res.insert(one);	
		}
		else if(i+1 < s.length() - 2){
			bool trace[len+1];
			trace[len] = true;
			trace[len-1] = false;
			if(s[i] != s[len-2] || s[i+1] != s[len-1]) trace[len-2] = true;
			else trace[len-2] = false;
			for(int j = len - 3; j >= i+2; j--){
				if(trace[j+3]) trace[j] = true;
				else{
					if(s[i] != s[len-2] || s[i+1] != s[len-1]){
						trace[j] = trace[j+2];
					}
				}
			}
			if(trace[i+2]) res.insert(string(s, i, 2));
		}
		
		
	}
	// if(s.length() - 2 >= 5) res.insert(string(s, s.length() - 2, 2));
	cout<<res.size()<<endl;
	for(set<string>::iterator it = res.begin(); it != res.end(); it++){
		cout<<*it<<endl;
	}

	return 0;

}
