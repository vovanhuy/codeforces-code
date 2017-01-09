#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

list<int> son[100005];
int n;
int num_ascendant[100005];
double expected_time[100005];

void fill_num_ascendant(int i){
	if(son[i].size() == 0) num_ascendant[i] = 1;
	else{
		for(auto fil : son[i]){
			fill_num_ascendant(fil);
			num_ascendant[i] += num_ascendant[fil];
		}
		num_ascendant[i]++;
	}
}

void fill_num_ascendant(){
	for(int i = 0; i < n; i++){
		num_ascendant[i] = 0;
	}
	fill_num_ascendant(0);
}

void fill_expected_time(int i){
	for(auto fil : son[i]){
		expected_time[fil] = expected_time[i] + 0.5 + 0.5 *(num_ascendant[i] - num_ascendant[fil]);
		fill_expected_time(fil);
	}
}

void fill_expected_time(){
	expected_time[0] = 1;
	fill_num_ascendant();
	fill_expected_time(0);
}

int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int x; cin >> x;
		son[x-1].push_back(i);
	}
	fill_expected_time();
	// for(int i = 0; i < n; i++)  cout << num_ascendant[i] << endl;
	for(int i = 0; i < n; i++){
		cout << std::fixed << setprecision(15) << expected_time[i];
		if(i == n - 1) cout << endl;
		else cout << " ";
	}

}