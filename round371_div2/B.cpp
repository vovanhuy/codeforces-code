#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	set<int> arr;
	for(int i = 0; i < n; i++){
		int a; scanf("%d", &a);
		arr.insert(a);
	}
	if(arr.size() < 3) printf("YES\n");
	else if(arr.size() == 3){
		set<int>::iterator it = arr.begin();
		int b[3];
		b[0] = *it;
		it++;
		b[1] = *it;
		it++;
		b[2] = *it;
		if(b[0]+b[2] == 2*b[1]) printf("YES\n");
		else printf("NO\n");
	}
	else printf("NO\n");

	return 0;
}