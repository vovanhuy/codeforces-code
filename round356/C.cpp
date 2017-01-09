#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int current = 0;
    // int times = 0;
    bool used2 = false;
    while (current < 15) {
        printf("%d\n", prime[current]);
        fflush(stdout);

        char response[20];
        scanf("%s", response);
        if (strcmp(response, "yes") == 0){
            if(used2){
            	printf("%s\n", "composite");
    			fflush(stdout);
    			return 0;
            }
            else if(prime[current] * prime[current] < 100){
            	printf("%d\n", prime[current] * prime[current]);
        		fflush(stdout);

        		char response2[20];
        		scanf("%s", response2);
        		if (strcmp(response2, "yes") == 0){
        			printf("%s\n", "composite");
    				fflush(stdout);
    				return 0;
        		}
        		else{
        			current++;
        			used2 = true;	
        		} 
            }
           
        	else{
    			current++;
    			used2 = true;	
    		}
        
        }
        else{
            current++;
        }
    }
    printf("%s\n", "prime");
    fflush(stdout);
    return 0;

}

