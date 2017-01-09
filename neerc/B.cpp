#include <cstdio>
#include <cstring>

using namespace std;
// #include <bits/stdc++.h>

int main() {
	int t;
	scanf("%d", &t);
	for(int k = 0; k < t;k++){
		int n;
		scanf("%d", &n);
		if( n == 1){
			printf("! 1 1\n");
			fflush(stdout);
			continue;
		}
		char p[5];
		int max_val[n/2+1];
		int min_val[n/2+1];
		for(int i = 0; i< n/2; i++){
			printf("? %d %d\n", 2*i+1, 2*i+2);
			fflush(stdout);
			
			scanf("%s", p);
			if(p[0] == '<'){
				min_val[i]=2*i;
				max_val[i] = 2*i+1;
			}
			else {
				max_val[i]=2*i;
				min_val[i] = 2*i+1;
			}
			
		}
		int maxx = max_val[0];
		int minn = min_val[0]; 
		for(int i = 1;i < n/2; i++){
			printf("? %d %d\n", maxx+1, max_val[i]+1);
			fflush(stdout);
			
			scanf("%s", p);
			if(p[0] == '<'){
				maxx = max_val[i];
			}
			
			printf("? %d %d\n", minn+1, min_val[i]+1);
			fflush(stdout);
			
			scanf("%s", p);
			if(p[0] == '>'){
				minn = min_val[i];
			}
		}
		if(n%2!=0){
			printf("? %d %d\n", maxx+1, n);
			fflush(stdout);
			
			scanf("%s", p);
			if(p[0] == '<'){
				maxx = n-1;
			}
			printf("? %d %d\n", minn+1, n);
			fflush(stdout);
			
			scanf("%s", p);
			if(p[0] == '>'){
				minn = n-1;
			}
		}
		printf("! %d %d\n", minn+1, maxx+1);
		fflush(stdout);
			
	}
	return 0;
		
	
}