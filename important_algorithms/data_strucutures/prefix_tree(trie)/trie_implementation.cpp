#include<bits/stdc++.h>
using namespace std;

struct Trie {
// data strucutures
	struct TrieNode {
		bool isLastWord = false;
		unordered_map<char, TrieNode*> children;
	};

// properties
	TrieNode *root = NULL;

// methods
	Trie() {
		root = new TrieNode();
	}

	void insert(const string& words) {
		TrieNode *curr = root;

		for(const char& c: words) {
			if(!curr->children[c])
				curr->children[c] = new TrieNode();

			curr = curr->children[c];
		}

		curr->isLastWord = true;
	}

	bool search(const string& words) const {
		TrieNode *curr = root;

		for(const char& c: words) {
			if(!curr->children[c])
				return false;

			curr = curr->children[c];
		}

		return curr->isLastWord;
	}

	bool startWith(const string& prefix) const {
		TrieNode *curr = root;

		for(const char& c: prefix) {
			if(!curr->children[c]) 
				return false;

			curr = curr->children[c];
		}

		return true;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << boolalpha;

	Trie *t = new Trie();
	t->insert("jaimin");
	t->insert("jane");
	t->insert("john");
	t->insert("elon musk");

	cout << t->search("jaimin") << '\n';
	cout << t->startWith("jay") << '\n';
	cout << t->startWith("jai") << '\n';




	return 0;
}