// Using Huffman coding

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>

using namespace std;

int main(){
	int n; cin >> n;
	int message[n];
	for(int i = 0; i < n; i++){
		cin >> message[i];
	}

	// create map of (character, frequence)
	map<int, int> freq;
	for(int i = 0; i < n; i++){
		if(freq.find(message[i]) == freq.end()){
			freq[message[i]] = 1;
		}
		else{
			freq[message[i]]++;
		}
	}

	// read querries
	int q; cin >> q;
	pair<int, int> querry[q];
	for(int i = 0; i < q; i++){
		cin >> querry[i].first >> querry[i].second;
	}

	if(freq.size() == 1){
		for(int i = 0; i < q; i++){
			cout << querry[i].second - querry[i].first - 1 << endl;
		}
	}
	else{
		// create vector of (charater, frequence)
		vector<pair<int, int> > key_value;
		for(auto character : freq){
			key_value.push_back(character);
		}

		// create map of (character, position in key_value)
		map<int, int> reverse_map;
		for(int i = 0; i < key_value.size(); i++){
			reverse_map[key_value[i].second] = i;
		}

		// create map of (character, frequence in huffman tree)
		multimap<int, int> huffman;
		for(int i = 0; i < key_value.size(); i++){
			huffman.insert(pair<int, int>(key_value[i].second, i));
		}

		// create graph
		vector<int> tree[2*key_value.size()-1];
		for(int i = 0; i < key_value.size(); i++){
			tree[i] = vector<int>();
		}


		for(int i = key_value.size(); i < 2*key_value.size() - 1; i++){
			multimap<int, int>::iterator it = huffman.begin();
			pair<int, int> first_node = *it;
			it++;
			pair<int, int> second_node = *it;
			// erase old nodes
			huffman.erase(huffman.begin());
			huffman.erase(huffman.begin());
			// insert new one
			huffman.insert(pair<int, int>(first_node.first + second_node.first, i));
			// update graph
			tree[i].push_back(first_node.second);
			tree[i].push_back(second_node.second);
		}

		// find length of huffman code
		int length[key_value.size()];
		stack<pair<int, int> > st;
		st.push(pair<int, int>(2*key_value.size()-2, 0));
		int global_length = 0;
		while(!st.empty()){
			pair<int, int> current_node = st.top(); st.pop();
			if(tree[current_node.first].size() == 0){
				length[current_node.first] = current_node.second;
			}
			else{
				st.push(pair<int, int>(tree[current_node.first][0], current_node.second + 1));
				st.push(pair<int, int>(tree[current_node.first][1], current_node.second + 1));
			}

		}

		// create a dp length table
		int dp[n+1];
		dp[0] = 0;
		for(int i = 1; i <= n;i++){
			dp[i] = dp[i-1] + length[reverse_map[character[i-1]]];
		}

		for(int i = 0; i < q; i++){
			cout << dp[querry.second]
		}

	}

	

	return 0;
}