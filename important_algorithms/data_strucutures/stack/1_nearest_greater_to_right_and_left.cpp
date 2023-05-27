#include<bits/stdc++.h>
using namespace std;

vector<int> basicBruteForce(vector<int>& v) {
	int n = v.size();
	vector<int> result(n, -1);

	for(int i = 0; i < n - 1; ++i) {
		for(int j = n - 1; j >= i + 1; --j) {
			if(v[j] > v[i]) 
				result[i] = v[j];
		}
	}

	// now, once you see that your second loop is depenent on i (first loop)
	// think, how you can implement this using Stack

	return result;
}


// AKA nearest greater to the right
vector<int> nextLargerElement(vector<int>& v) {
	// [1, 3, 2, 4] => [3, 4, 4, -1] 
	vector<int> result;
	stack<int> s;
	const int n = v.size();

	for(int i = n - 1; i >= 0; --i) {

		if(s.empty()) 
			result.push_back(-1);

		else if(!s.empty() && s.top() > v[i]) 
			result.push_back(s.top());

		else if(!s.empty() && s.top() <= v[i]) {

			while(!s.empty() && s.top() <= v[i]) 
				s.pop();

			if(s.empty()) 
				result.push_back(-1);
			else 
				result.push_back(s.top());
		}

		s.push(v[i]); // do not forget this step

	}

	reverse(result.begin(), result.end());
	return result;
}

vector<int> previousLargerElement(vector<int>& v) {
	// [1, 3, 2, 4] => [-1, -1, 3, -1] 
	int n = v.size();
	vector<int> res;
	stack<int> s;

	for(int i = 0; i < n; ++i) {
		if(s.empty())
			res.push_back(-1);
		else if(!s.empty() && s.top() > v[i])
			res.push_back(s.top());
		else if(!s.empty() && s.top() <= v[i]) {

			while(!s.empty() && s.top() <= v[i]) 
				s.pop();

			if(s.empty()) 
				res.push_back(-1);
			else
				res.push_back(s.top());

		}

		s.push(v[i]);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {1, 3, 2, 4};

	// O(N ^ 2)
	vector<int> result = basicBruteForce(v);
	for(auto& el: result)
		cout << el << ' ';
	cout << '\n';


	// O(N)
	vector<int> resultAgain = nextLargerElement(v);
	for(auto& el: resultAgain)
		cout << el << ' ';
	cout << '\n';

	vector<int> presult = previousLargerElement(v);
	for(auto& el: presult)
		cout << el << ' ';
	cout << '\n';

	return 0;
}