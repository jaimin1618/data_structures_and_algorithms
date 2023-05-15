#include<bits/stdc++.h>
using namespace std;

/***

Core concept of, 
- Sorting array recursively, 
- Sorting stack recursively,
Are implemented here in easy problem

Code: 
Most IMP part of code
"""
	int tmp = s.top();
	s.pop(); ---> remove 
	solve(s, k - 1); ---> go further without
	s.push(k); ---> add after recursion
"""

MAIN/CORE part of recursion. to make choice

"""

	int tmp = s.top();
	s.pop(); ---> remove 
	int c1 = solve(s, k - 1); ---> choice 1
	int c2 = solve(s, k - 2); ---> choice 2
	
	if(c1) {
		// do this
	} else if(c2) {
		// do this
	} else {
		s.push(k); ---> add after recursion
	}
	
"""

Understand important Recursion aspect here:
https://www.youtube.com/watch?v=oCcUNRMl7dA&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=8
***/

class Solution {
public:
	static void print(stack<int>& s) {
		while(!s.empty()) {
			cout << s.top() << ' ';
			s.pop();
		}
	}
	
	static void solve(stack<int>& s, int k) {
		if(k == 1) {
			s.pop();
			return;
		}
		
		int tmp = s.top();
		s.pop();
		solve(s, k - 1);
		s.push(k);		
	}
	
	static stack<int> removeMidElement(stack<int>& s) {
		if(s.empty())
			return s;
		
		int k = 1 + s.size() / 2;
		solve(s, k);	
		return s;
	}
};	

int main() {
	stack<int> s;
	s.push(1);
	s.push(3);
	s.push(5);
	s.push(7);
	s.push(9);
	print(s);
	
	int K = 1 + s.size() / 2;
	removeMiddleElement(s, K);
	print(s);

	return 0;
}
