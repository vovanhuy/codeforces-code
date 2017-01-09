
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




int main(){
	int q; cin >> q;
	map<PLL, long long> fee;
	for(int i = 0; i < q; i++){
		int type_event; cin >> type_event;
		if(type_event == 1){
			long long u, v, w;
			cin >> u >> v >> w;
			int length_u = findLength(u, 2);
			int length_v = findLength(v, 2);
			int bin_u[length_u];
			int bin_v[length_v];
			factor(bin_u, 2, u, length_u);
			factor(bin_v, 2, v, length_v);
			// display(bin_u, length_u);
			// display(bin_v, length_v);
			long long current_val = 0;
			int last_pos;
			for(int j = 0; j < min(length_u, length_v); j++){
				if(bin_u[j] != bin_v[j]) break;
				else{
					last_pos = j;
					current_val = 2*current_val + bin_u[j];
				}
			}
			long long val_u = current_val;
			for(int j = last_pos + 1; j < length_u; j++){
				if(fee.find(PLL(val_u, 2*val_u + bin_u[j])) == fee.end()){
					fee[PLL(val_u, 2*val_u + bin_u[j])] = w;
				}
				else{
					fee[PLL(val_u, 2*val_u + bin_u[j])] += w;	
				}
				val_u = 2*val_u + bin_u[j];
			}
			long long val_v = current_val;
			for(int j = last_pos + 1; j < length_v; j++){
				if(fee.find(PLL(val_v, 2*val_v + bin_v[j])) == fee.end()){
					fee[PLL(val_v, 2*val_v + bin_v[j])] = w;
				}
				else{
					fee[PLL(val_v, 2*val_v + bin_v[j])] += w;	
				}
				val_v = 2*val_v + bin_v[j];
			}

			// for(auto el : fee){
			// 	cout << el.first.first << " " << el.first.second << " " << el.second << endl;
			// }
		}
		else{
			long long u, v; cin >> u >> v;
			int length_u = findLength(u, 2);
			int length_v = findLength(v, 2);
			int bin_u[length_u];
			int bin_v[length_v];
			factor(bin_u, 2, u, length_u);
			factor(bin_v, 2, v, length_v);

			long long cost = 0;
			long long current_val = 0;
			int last_pos;
			for(int j = 0; j < min(length_u, length_v); j++){
				if(bin_u[j] != bin_v[j]) break;
				else{
					last_pos = j;
					current_val = 2*current_val + bin_u[j];
				}
			}
			long long val_u = current_val;
			for(int j = last_pos + 1; j < length_u; j++){
				if(fee.find(PLL(val_u, 2*val_u + bin_u[j])) == fee.end()){
					cost += 0;
				}
				else{
					cost += fee[PLL(val_u, 2*val_u + bin_u[j])];
				}
				val_u = 2*val_u + bin_u[j];
			}
			long long val_v = current_val;
			for(int j = last_pos + 1; j < length_v; j++){
				if(fee.find(PLL(val_v, 2*val_v + bin_v[j])) == fee.end()){
					cost += 0;
				}
				else{
					cost += fee[PLL(val_v, 2*val_v + bin_v[j])];	
				}
				val_v = 2*val_v + bin_v[j];
			}
			cout << cost << endl;
		}
	}
	
	
	return 0;

}
