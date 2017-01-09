#include <bits/stdc++.h>

using namespace std;

#define ll long long

int freq[300000];

void init(){
	for(int i = 0; i < 300000; i++){
		freq[i] = 0;
	}
}

int find_pos(ll num){
	if(num == 0) return 0;
	else return 2 * find_pos(num/10) + num%2;
}

int main(){
	int t; scanf("%d", &t);
	init();
	for(int i = 0; i < t; i++){
		char command[2];
		scanf("%s", command);
		if(command[0] == '+'){
			ll num; scanf("%I64d", &num);
			freq[find_pos(num)]++;
		}
		if(command[0] == '-'){
			ll num; scanf("%I64d", &num);
			freq[find_pos(num)]--;
		}
		if(command[0] == '?'){
			ll num; scanf("%I64d", &num);
			printf("%d\n", freq[find_pos(num)]);
		}
	}

}