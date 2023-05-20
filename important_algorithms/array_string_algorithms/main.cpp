#include<bits/stdc++.h>
using namespace std;

struct Trie {
	struct TrieNode {
		unordered_map<char, TrieNode*> children;
		bool isLastWord = false;
	};

	TrieNode *root = NULL;

	Trie() {
		root = new TrieNode();
	}

	void insert() {};
	bool search() const {};
	bool startsWith() const {};
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	

	return 0;
}