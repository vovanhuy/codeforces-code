

#include <iostream>
#include <queue>
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
	bool operator()(PII a, PII b){
		if(a.second != b.second) return a.second > b.second;
		return a.first > b.first;
	}
};


int main(){
	int n, m; //cin>>n>>m;
	scanf("%d %d\n", &n, &m);

	int adjacent[n][n];
	vector<int> neigbor[n];
	//initialise adjacent matrix
	for(int i = 0; i < n; i++) initialise(adjacent[i], 0, n);
	//read graph
	for(int i = 0; i < m; i++){
		int u, v; //cin>>u>>v;
		scanf("%d %d\n", &u, &v);
		
		if(adjacent[u-1][v-1] == 0){
			adjacent[u-1][v-1] = 1;
			neigbor[u-1].push_back(v-1);
		}
	}

	set<PII, comp> in[n];
	set<PII, comp> out[n];
	int distance[n][n];

	// for(int i = 0; i < n; i++){
	// 	initialise(distance[i], -1, n);
	// }
	for(int i = 0; i < n; i++){
		bool trace[n];
		initialise(trace, false, n);
		queue<PII> file;
		file.push(PII(i, 0));
		while(!file.empty()){
			int curr = file.front().first;
			int currVal = file.front().second;
			//store the shortest path from i to curr in two containers
			out[i].insert(PII(curr, currVal));
			in[curr].insert(PII(i, currVal));
			distance[i][curr] = currVal;
			//mark that curr has been visited
			trace[curr] = true;
			for(int j = 0; j < neigbor[curr].size(); j++){
				if(trace[neigbor[curr][j]] == false){
					file.push(PII(neigbor[curr][j], currVal+1));
				}
			}
			file.pop();
		}
	}

	// for(int i = 0; i < n;i++) display(distance[i], n);

	int one, two, three, four;
	int max = 0;
	for(int i = 0; i < n; i++){
		int left, right;
		
		if(in[i].size() == 1 || out[i].size() == 1) continue;

		for(set<PII>::iterator iter = out[i].begin(); iter != out[i].end(); iter++){
			int j = iter->first;

			if(j == i || out[j].size() == 1) continue;

			set<PII>::iterator it12 = in[i].begin();
			set<PII>::iterator it11 = it12++;
			left = it11->first;
			if(left == j){
				left = it12->first;
				if(left == i) break;
				else{
					it11 = it12++;
				}
			} 

			set<PII>::iterator it22 = out[j].begin();
			set<PII>::iterator it21 = it22++;
			right = it21->first;
			if(right == i){
				right = it22->first;
				if(right == j) continue;
				else it21 = it22++;
			}


			if(left != right){
				if(max < distance[left][i] + distance[i][j] + distance[j][right]){
					max = distance[left][i] + distance[i][j] + distance[j][right];
					one = left;
					two = i;
					three = j;
					four = right;
				}
			}
			else{
				if(it12->second == 0 && it22->second == 0) continue;
				if(it12->second != 0 && it22->second == 0){
					left = it12->first;
					if(max < distance[left][i] + distance[i][j] + distance[j][right]){
						max = distance[left][i] + distance[i][j] + distance[j][right];
						one = left;
						two = i;
						three = j;
						four = right;
					}
				}
				if(it12->second == 0 && it22->second != 0){
					right = it22->first;
					if(max < distance[left][i] + distance[i][j] + distance[j][right]){
						max = distance[left][i] + distance[i][j] + distance[j][right];
						one = left;
						two = i;
						three = j;
						four = right;
					}
				}
				if(it12->second != 0 && it22->second != 0){
					left = it12->first;
					if(max < distance[left][i] + distance[i][j] + distance[j][right]){
						max = distance[left][i] + distance[i][j] + distance[j][right];
						one = left;
						two = i;
						three = j;
						four = right;
					}
					left = it11->first;
					right = it22->first;
					if(max < distance[left][i] + distance[i][j] + distance[j][right]){
						max = distance[left][i] + distance[i][j] + distance[j][right];
						one = left;
						two = i;
						three = j;
						four = right;
					}
				}
			}
		}
	}

	cout<<one+1<<" "<<two+1<<" "<<three+1<<" "<<four+1<<endl;




	return 0;

}
