#include<bits/stdc++.h>
using namespace std;

struct Animal {
	string name;
	int id;
	float weight;
};

int main() {
	// destructuring objects into variables in C++
	auto [ name, ID, weight ] = Animal { "Lion", 10, 30.75 };
	cout << name << "=" << ID << "=" << weight << '\n';

	// using tie function for Pair & Tuple
	tuple<int,bool,string> user {10, true, "Jaimin"};
	int id;
	bool isMale;
	string fname;
	tie(id, isMale, fname) = user;
	cout << id << " " << isMale << " " << fname << '\n';

	// pair destructuring
	pair<string,int> frq {"Jaimin", 7};
	// OR pair<string,int> frq = make_pair("Jaimin", 7);
	string key;
	int value;
	tie(key, value) = frq;
	cout << key << ": " << value << '\n';
	// ignoring content
	tie(std::ignore, value) = frq; // to ignore "key"
	cout << value << '\n';

	return 0;
}