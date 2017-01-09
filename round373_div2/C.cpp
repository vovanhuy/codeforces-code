#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int n, t; scanf("%d%d", &n, &t);
	char number[200005];
	scanf("%s", number);

	// find position of "."
	int dot_position;
	for(int i = 0; i < n; i++){
		if(number[i] == '.'){
			dot_position = i;
			break;
		}
	}
	int min_step[n];
	min_step[n-1] = t+1;
	for(int i = n-2; i > dot_position; i--){
		if(number[i+1] >= '5') min_step[i] = 1;
		else if(number[i+1] == '4') min_step[i] = min_step[i+1] == t+1 ? t+1 : min_step[i+1] + 1;
		else min_step[i] = t+1;
	}
	min_step[dot_position] = t+1;
	if(number[dot_position+1] >= '5') min_step[dot_position-1] = 1;
	else if(number[dot_position+1] == '4') min_step[dot_position-1] = min_step[dot_position+1] == t+1 ? t+1 : min_step[dot_position+1] + 1;
	else min_step[dot_position-1] = t+1;

	for(int i = dot_position-2; i>=0; i--){
		if(number[i+1] == '9') min_step[i] = min_step[i+1];
		else{
			min_step[i] = t+1;
		}
	}

	// find most beneficial round 
	int final_pos = -1;
	for(int i = 0; i < n; i++){
		if(min_step[i] <= t){
			final_pos = i;
			break;
		}
	}

	if(final_pos == 0){
		if(number[0] == '9'){
			printf("%c", '1');
			for(int i = 0; i < dot_position; i++){
				printf("%c", '0');
			}
			printf("\n");
		}
		else{
			printf("%c", (char)((int)number[0] + 1));
			for(int i = 1; i < dot_position; i++){
				printf("%c", '0');
			}
			printf("\n");	
		}
	}
	else if(final_pos == -1){
		for(int i = 0; i < n; i++){
			printf("%c", number[i]);
		}
		printf("\n");
	}
	else if(final_pos < dot_position){
		for(int i = 0; i < final_pos; i++){
			printf("%c", number[i]);
		}
		printf("%c", (char)((int)number[final_pos] + 1));
		for(int i = final_pos+1; i < dot_position; i++){
			printf("%c", '0');
		}
		printf("\n");
	}
	else{
		for(int i = 0; i < final_pos; i++){
			printf("%c", number[i]);	
		}
		printf("%c", (char)((int)number[final_pos] + 1));
		printf("\n");
	}

	return 0;
}