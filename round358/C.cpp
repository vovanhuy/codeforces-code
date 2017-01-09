#include <iostream>
#include <limits>
#include <list>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef pair< long long, long long > PLL;

int n;
long long vertexValue[100005];
list<PLL> neighbor[100005];
int count[100005];
int level[100005];
int result = 0;


void fillCount(int node){
	if(neighbor[node].size() == 0){
		count[node] = 1;
		return;
	}
	else{
		count[node] = 0;
		for(auto son : neighbor[node]){
			if(level[son.first] > level[node]){
				fillCount(son.first);
				count[node] += count[son.first];
			}
		}
		count[node] += 1;
	}
}

void fillLevel(){
	for(int i = 0; i < n; i++){
		level[i] = -1;
	}
	level[0] = 0;
	queue<int> st;
	st.push(0);
	while(!st.empty()){
		int current = st.front(); st.pop();
		for(auto son : neighbor[current]){
			if(level[son.first] == -1){
				st.push(son.first);
				level[son.first] = level[current] + 1;
			}
		}
	}
}

void solve(int node, long long weight){
	for(auto son : neighbor[node]){
		if(level[son.first] > level[node]){
			if(son.second + weight > vertexValue[son.first]){
				result += count[son.first];
			}
			else{
				if(weight + son.second > 0) solve(son.first, weight + son.second);
				else solve(son.first, 0);
			}
		}
	}
}

void solve(){
	fillLevel();
	fillCount(0);
	solve(0, 0);
}



int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> vertexValue[i];
	}

	for(int i = 0; i < n - 1; i++){
		int p;
		long long c; 
		cin >> p >> c;
		neighbor[i+1].push_back(PLL(p-1, c));
		neighbor[p-1].push_back(PLL(i+1, c));
	}

	solve();
	// for(int i = 0; i < n; i++){
	// 	cout << "level " << i << ": " << level[i] << endl;
	// }
	// for(int i = 0; i < n; i++){
	// 	cout << "count " << i << ": " << count[i] << endl;
	// }
	// for(int i = 0; i < n; i++){
	// 	cout << "neighbor " << i << ": " << endl;
	// 	for(auto son : neighbor[i]){
	// 		cout << "son " << son.first << " " << son.second << endl;
	// 	}
	// }
	cout << result << endl;


}