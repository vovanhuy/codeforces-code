
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
#include <time.h>
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

vector<long long> prime_divisor;
vector<int> prime_power;
vector<int> weight;

// encode and decode a vector in with fixed length and fixed range of value of all components
// value range of power_vec[i] is [0, prime_power[i]];

int vec2int(int power_vec[]){
	int result = 0;
	for(int i = 0; i < prime_power.size(); i++){
		result += weight[i] * power_vec[i];
	}
	return result;
}

void int2vec(int prime_vec[], int a){
	for(int i = 0; i < prime_power.size(); i++){
		prime_vec[i] = a/weight[i];
		a %= weight[i];
	}
}

int main(){

	clock_t tStart = clock();

	int n;
	long long k;
	scanf("%d %llu", &n, &k);

	// b is just an copy of a, used later
	long long a[n];
	long long b[n];
	for(int i = 0; i < n; i++){
		scanf("%llu", &a[i]);
		b[i] = a[i];
	}

	// in case k = 1, we need only on element, need to choose a minimum element in a
	if(k == 1){
		cout << 1 << endl;
		long long min_val = a[0];
		int min_pos = 1;
		for(int i = 0; i < n; i++){
			if(a[i] < min_val){
				min_val = a[i];
				min_pos = i + 1;
			}
		}
		cout << min_pos << endl;
		return 0;
	}

	// compute the list of all prime number smaller than 1000000
	bool check_prime[1000000];
	initialise(check_prime, true, 1000000);
	check_prime[0] = check_prime[1] =false;

	int count_prime = 0;
	for(int i = 2; i < 1000000; i++){
		if(check_prime[i]){
			count_prime++;
			for(int factor = 2; factor * i < 1000000; factor++){
				check_prime[factor * i] = false;
			}
		}
	}

	// cout << count_prime << endl;

	int prime_num[count_prime];
	int current_prime_pos = 0;
	for(int i = 0; i < 1000000; i++){
		if(check_prime[i]){
			prime_num[current_prime_pos] = i;
			current_prime_pos++;
		}
	}

	// factorization of k
	for(int i = 0; i < count_prime; i++){
		if(k % prime_num[i] == 0){
			prime_divisor.push_back(prime_num[i]);
			prime_power.push_back(0);
			weight.push_back(0);
		}
		while(k % prime_num[i] == 0){
			prime_power[prime_power.size() - 1]++;
			k /= prime_num[i];
		}
	}

	if(k > 1){
		prime_divisor.push_back(k);
		prime_power.push_back(1);
		weight.push_back(0);
	}


	// cout << weight.size() << " " << prime_power.size() << endl;

	// weight is use to convert an int to a vector and vice versa, used in dp step
	weight[prime_power.size() - 1] = 1;
	for(int i = prime_power.size() - 2; i >= 0; i--){
		weight[i] = weight[i+1] * (prime_power[i+1]+1);
	}

	// display(prime_divisor);
	// display(prime_power);
	// display(weight);


	//dp part
	// factorizatio of all a[i]
	long long a_prime_power[n][prime_power.size()];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < prime_power.size(); j++){
			a_prime_power[i][j] = 0;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < prime_power.size(); j++){
			while(b[i] % prime_divisor[j] == 0){
				a_prime_power[i][j]++;
				b[i] /= prime_divisor[j];
			}
		}
	}
	// dp simple in idea: for a[n] we have to option: choose or not choose a[n]
	// but implementation is complicated because a parameter in dp is a vector, so we need a way to transform a vector in an interger
	pair<int, long long> result[n+1][weight[0] * (prime_power[0]+1)]; 
	for(int i = 0; i < weight[0] * (prime_power[0]+1); i++){
		result[0][i] = pair<int, long long>(n + 1, (long long)1e18);
	}
	for(int i = 0; i <= n; i++){
		result[i][0] = pair<int, long long>(0, 0);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < weight[0] * (prime_power[0]+1); j++){
			// cout << i << " " << j << endl;

			// compute after_substration in case we choose a[i-1]
			int power_vec[prime_power.size()];
			int2vec(power_vec, j);
			// display(power_vec, prime_power.size());
			// display(a_prime_power[i-1], prime_power.size());
			// cout << prime_power.size() << endl;
			for(int l = 0; l < prime_power.size(); l++){
				power_vec[l] = 0 > power_vec[l] - a_prime_power[i-1][l] ? 0 : power_vec[l] - a_prime_power[i-1][l];
				// cout << "power_vec[" << l << "] :" << power_vec[l] << endl;
			}
			int after_substration = vec2int(power_vec);

			if(result[i-1][j].first == n+1 && result[i-1][after_substration].first == n+1){
				result[i][j] = result[i-1][j];
			}
			else if(result[i-1][j].first == n+1){
				result[i][j].first = 1 + result[i-1][after_substration].first;
				result[i][j].second = result[i-1][after_substration].second + a[i-1];
			}
			else if(result[i-1][after_substration].first == n+1){
				result[i][j] = result[i-1][j];
			}
			else{
				if(result[i-1][j].first < 1 + result[i-1][after_substration].first){
					result[i][j] = result[i-1][j];
				}
				else if(result[i-1][j].first > 1 + result[i-1][after_substration].first){
					result[i][j].first = 1 + result[i-1][after_substration].first;
					result[i][j].second = a[i-1] + result[i-1][after_substration].second;
				}
				else{
					result[i][j].first = result[i-1][j].first;
					result[i][j].second = min(result[i-1][j].second, a[i-1] + result[i-1][after_substration].second);
				}
			}


		}
	}

	if(result[n][weight[0] * (prime_power[0]+1) - 1].first > n){
		cout << -1 << endl;
		return 0;
	}

	cout << result[n][weight[0] * (prime_power[0]+1) - 1].first << endl;

	//********** go back to trace the optimal solution**************************//
	vector<int> result_vec;
	int curent_pos = n;
	int current_vec = weight[0] * (prime_power[0]+1) - 1;
	while(result[curent_pos][current_vec].first != 0){
		
		int power_vec[prime_power.size()];
		int2vec(power_vec, current_vec);
		// display(power_vec, prime_power.size());
		// display(a_prime_power[i-1], prime_power.size());
		// cout << prime_power.size() << endl;
		for(int l = 0; l < prime_power.size(); l++){
			power_vec[l] = 0 > power_vec[l] - a_prime_power[curent_pos-1][l] ? 0 : power_vec[l] - a_prime_power[curent_pos-1][l];
			// cout << "power_vec[" << l << "] :" << power_vec[l] << endl;
		}
		int after_substration = vec2int(power_vec);

		if(result[curent_pos-1][current_vec].first < 1 + result[curent_pos-1][after_substration].first){
			curent_pos--;
		}
		else if(result[curent_pos-1][current_vec].first < 1 + result[curent_pos-1][after_substration].first){
			result_vec.push_back(curent_pos);
			curent_pos--;
			current_vec = after_substration;
		}
		else{
			if(result[curent_pos][current_vec].second == result[curent_pos-1][current_vec].second){
				curent_pos--;
			}
			else{
				result_vec.push_back(curent_pos);
				curent_pos--;
				current_vec = after_substration;
			}
		}


		
		
		
	}

	display(result_vec);

	
	// printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;

}
 