
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

bool prior(int n, string a){
	for(int i = 0; i < a.length(); i++){
		if(n < (int)a[i]-48) return true;
		else if(n > (int)a[i]-48) return false;
	}
	return true;
}

int prior(char a[], char b[], int len){
	for(int i = 0; i < len; i++){
		if(a[i] < b[i]) return 1;
		else if(a[i] > b[i]) return -1;
	}

	return 0;
}


int priorShort(string a, string b){
	for(int i = 0; i < min(a.length(), b.length()); i++){
		if(a[i] < b[i]) return 1;
	}
	if(a.length() < b.length()) return 1;
	else if(a.length() > b.length()) return -1;
	else return 0;
}

int priorLong(string a, string b){
	for(int i = 0; i < min(a.length(), b.length()); i++){
		if(a[i] < b[i]) return 1;
	}
	if(a.length() < b.length()) return -1;
	else if(a.length() > b.length()) return 1;
	else return 0;
}


int main(){
	string s; cin>>s;
	string sub; cin>>sub;
	int len = s.length();
	if(len == 2 && ((s[0] == '0' && s[1] == '1') || (s[0] == '1' && s[1] == '0'))){
		cout<<0<<endl;
		return 0;
	}

	int power = 1;
	int lenOfWord;
	for(int i = 0; i <= 6; i++){
		int n = len - i - 1;
		if(10* power > n && n >= power){
			lenOfWord = n;
			break;
		}
		else power *= 10;
	}

	// cout<<lenOfWord<<endl;

	int count[10];
	initialise(count, 0, 10);

	for(int i = 0; i < len; i++){
		count[(int)s[i] - 48]++;
	}

	for(int i = 0; i < sub.length(); i++){
		count[(int)sub[i] - 48]--;
	}	

	int str[findLength(lenOfWord, 10)];
	factor(str, 10, lenOfWord, findLength(lenOfWord, 10));

	for(int i = 0; i < findLength(lenOfWord, 10); i++){
		count[str[i]]--;
	}

	// display(count, 10);

	// display(str, findLength(lenOfWord, 10));


	bool isPrinted = false;
	int first = -1;
	for(int i = 1; i < 10; i++){
		if(count[i] != 0){
			first = i;
			break;
		}
	}

	// cout<<"first: "<<first<<endl;
	if(first == -1){
		cout<<sub;
		isPrinted = true;
		for(int i = 0; i < count[0]; i++){
			cout<<0;
		}
		cout<<endl;
		return 0;
	}
	else if(sub[0] == '0'){
		cout<<first;
		count[first]--;
		for(int i = 0; i < count[0]; i++){
			cout<<0;
		}
		cout<<sub;
		isPrinted = true;
	}
	else if(first > (int)sub[0] - 48){
		cout<<sub;
		isPrinted = true;
		for(int i = 0; i < count[0]; i++){
			cout<<0;
		}
	}
	else if(first < (int)sub[0] - 48){
		cout<<first;
		count[first]--;
		for(int i = 0; i < count[0]; i++){
			cout<<0;
		}
	}
	else{
		char lineOne[1 + count[0] + sub.length()];
		char lineTwo[1 + count[0] + sub.length()];
		lineOne[0] = (char)(first + 48);
		for(int i = 1; i < 1 + count[0]; i++){
			lineOne[i] = '0';
		}
		for(int i = 1+count[0]; i < 1 + count[0] + sub.length(); i++){
			lineOne[i] = sub[i - 1 - count[0]];
		}
		
		// cout<<lineOne<<endl;
		for(int i = 0; i < sub.length(); i++){
			lineTwo[i] = sub[i];
		}

		for(int i = sub.length(); i <count[0] + sub.length(); i++){
			lineTwo[i] = '0';
		}
		lineTwo[1 + count[0] + sub.length()-1] = (char)(first + 48);

		if(prior(lineOne, lineTwo, 1 + count[0] + sub.length()) >= 0){
			cout<<first;
			count[first]--;
			for(int i = 0; i < count[0]; i++){
				cout<<0;
			}
		}
		else{
			cout<<lineTwo;
			isPrinted = true;
			count[first]--;
		}
	}

	for(int i = first; i < 10; i++){
		if(isPrinted){
			for(int j = 0; j < count[i]; j++) cout<<i;
		}
		else{
			if(prior(i, sub)){
				for(int j = 0; j < count[i]; j++) cout<<i;		
			}
			else{
				cout<<sub;
				isPrinted = true;
				for(int j = 0; j < count[i]; j++) cout<<i;
			}
		}
	}

	if(!isPrinted) cout<<sub;

	cout<<endl;
	
	return 0;

}
