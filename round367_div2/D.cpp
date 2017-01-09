
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <time.h>
#include <assert.h>
//#include <unordered_map>



using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<double, double> PDD;

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

template<typename T>
void display(vector<T> a){
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


// idea, we denote numbers in binary form and create a forest of binary trees number[] where number[i] is the tree containing numbers whose 
// length in binary form is i. Each number is represented by a path in the corresponding tree whose each edge is either 0 or 1.
// Each tree is represented by an object of class biNum which contains 4 fields: value, frequency, left, right: value is the bit it represents, 
// frequency is the number of numbers in the multisets whose representing path contains this node, left is the left child of current node (the edge
// from current node to its left child represents 0), right is the right child of current node (the edge from current node to its right child
// represents 1).

// adding a number to the forest means updating the corresponding tree by adding node and increasing frequency
// deleting a number from the forest means updating the corresponding tree by deleting node and reducing frequency
// to find max(x XOR y): if the forest contain an element whose length is greater than the one of x, choose the tree number[length], otherwise
// find the leftmost 0-bit in x, suppose this is the bit i from the right, and choose the tree number[i], if all bits in x are 1, then return x
// After finding the right tree, the remaining task is just to go down the tree and at each position to choose the right bit maximizing the final result.

class biNum
{
	public:
		int value;
		int frequency;
		biNum *left;
		biNum *right;

		biNum(int val, int freq, biNum* l, biNum* r){
			value = val;
			frequency = freq;
			left = l;
			right = r;
		}
};


biNum* number[31];

void add(int binary_num[], int length){
	biNum* current = number[length];
	for(int i = 0; i < length; i++){
		if(binary[i] == 0){
			if(current->left == NULL){
				current->left = new biNum(0, 1, NULL, NULL);
			}
			else current->left->frequency++;
			current = current->left;
		}
		else{
			if(current->right == NULL){
				current->right = new biNum(1, 1, NULL, NULL);
			}
			else current->right->frequency++;
			current = current->right;
		}
	}
}

int find_rank(int binary_num[], int length){
	int result = 0;
	for(int i = 0; i < length; i++){
		if(number[i].left != NULL) result += number[i].left->frequency;
		if(number[i].right != NULL) result += number[i].right->frequency;
	}

	biNum* current = number[length];
	for(int i = 0; i < length; i++){
		if(current == NULL) break;
		if(binary_num[i] == 0){
			current = current->left;
		}
		else{
			if(current->left != NULL) result += current->left->frequency;
			current = current->right;
		}
	}
}

int get_xor(int binary[], int length, int length_sum){
	biNum* current = number[length_sum];

	// fill result[length_sum -1] to result[length] 
	if(length_sum > length){
		int result[length_sum];

		for(int i = length_sum; i >= length + 1; i--){
			if(current->right != NULL){
				result[i-1] = 1;
				current = current->right;
			}
			else{
				result[i-1] = 0;
				current = current->left;
			}
		}

		// fill result[length - 1]
		if(current->left != NULL){
			result[length-1] = 1;
			current = current->left;
		}
		else{
			result[length-1] = 0;
			current = current->right;
		}

		// fill the rest
		for(int i = length-1; i >= 1; i--){
			if(binary[length - i] == 0){
				if(current->right != NULL){
					result[i-1] = 1;
					current = current->right;
				}
				else{
					result[i-1] = 0;
					current = current->left;
				}
			}
			else{
				if(current->left != NULL){
					result[i-1] = 1;
					current = current->left;
				}
				else{
					result[i-1] = 0;
					current = current->right;
				}
			}
		}
		int final_result = 0;
		int currentPower = 1;
		// display(result, length_sum);
		for(int i = 0; i < length_sum; i++){
			final_result += result[i] * (1<<i);
			currentPower *= 2;
		}

		return final_result;
	}
	else{
		int result[length];
		for(int i = 0; i < length - length_sum; i++){
			result[length - i - 1] = binary[i];
		}

		for(int i = length_sum; i >= 1; i--){
			if(binary[length - i] == 0){
				if(current->right != NULL){
					result[i-1] = 1;
					current = current->right;
				}
				else{
					result[i-1] = 0;
					current = current->left;
				}
			}
			else{
				if(current->left != NULL){
					result[i-1] = 1;
					current = current->left;
				}
				else{
					result[i-1] = 0;
					current = current->right;
				}
			}
		}

		int final_result = 0;
		int currentPower = 1;
		// display(result, length);
		for(int i = 0; i < length; i++){
			final_result += result[i] * currentPower;
			currentPower *= 2;
		}

		return final_result;

	}
	

	// fill the rest




}


int main(){
	 clock_t tStart = clock();
	 vector<int> res_to_print;

	 int q; scanf("%d", &q);
	 
	 for(int i = 0; i < 31; i++){
	 	number[i] = new biNum(-1, -1, NULL, NULL);
	 }
	 // for(int i = 0; i < 31; i++){
	 // 	cout << (number[i]->right != NULL);
	 // }

	
	 for(int querry = 0; querry < q; querry++){
	 	
	 	string sign; cin >> sign;
	 	string s_num; cin >> s_num;
	 	stringstream ss(s_num);
	 	int num; ss >> num;
	 	int length = findLength(num, 2);
		int binary[length];
		factor(binary, 2, num, length);
		// display(binary, length);
	 	
	 	if(sign[0] == '+'){
 			biNum* current = number[length];
 			for(int i = 0; i < length; i++){
 				if(binary[i] == 0){
 					if(current->left == NULL){
 						current->left = new biNum(0, 1, NULL, NULL);
 					}
 					else current->left->frequency++;
 					current = current->left;
 				}
 				else{
 					if(current->right == NULL){
 						current->right = new biNum(1, 1, NULL, NULL);
 					}
 					else current->right->frequency++;
 					current = current->right;
 				}
 			}
	 	}
	 	if(sign[0] == '-'){
 			biNum* current = number[length];
 			for(int i = 0; i < length; i++){
 				if(binary[i] == 0){
 					if(current->left->frequency == 1){
 						// current->left->~biNum();
 						// delete current->left;
 						current->left = NULL;
 						break;
 					}
 					else{
 						current->left->frequency--;
 						current = current->left;
 					}
 				}
 				else{
 					if(current->right->frequency == 1){
 						// current->right->~biNum();
 						// delete current->right;
 						current->right = NULL;
 						break;
 					}
 					else{
 						current->right->frequency--;
 						current = current->right;
 					}
 				}
 			}
	 	}
	 	if(sign[0] == '?'){
	 		int length_sum = 0;
	 		for(int i = 30; i > length; i--){
	 			if(number[i]->right != NULL){
	 				length_sum = i;
	 				break;
	 			}
	 		}

	 	// 	for(int i = 0; i < 31; i++){
			//  	cout << (number[i]->right != NULL);
			// }
			// cout << endl;

	 		if(length_sum > 0){
	 			// cout << "length_sum: " << length_sum << endl;
	 			res_to_print.push_back(get_xor(binary, length, length_sum));
	 		}
	 		else{
	 			length_sum = 0;
	 			for(int i = 1; i < length; i++){
	 				if(binary[i] == 0 && number[length - i]->right != NULL){
	 					// cout << "i: " << i << endl;
	 					length_sum = length - i;
	 					break;
	 				}
	 			}
	 			// cout << "length_sum length: " << length_sum << " " << length << endl;
	 			if(length_sum > 0) res_to_print.push_back(get_xor(binary, length, length_sum));
	 			else res_to_print.push_back(num);
	 		}
	 	}
	 }

	 for(int i = 0; i < res_to_print.size(); i++){
	 	printf("%d\n", res_to_print[i]);
	 }









    /* Do your stuff here */
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;

}
