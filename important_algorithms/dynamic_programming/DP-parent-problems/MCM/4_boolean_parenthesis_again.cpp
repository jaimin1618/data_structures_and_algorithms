#include<bits/stdc++.h>
using namespace std;

/*==============================
IP: String (T|F&T), string consists of T, F, |, &, ^ symbols
OP: Int (number of ways of putting brackets to evaluate express TRUE)

solution using MCM approach, 
We need to put brackets between binary operation terms

T|F&T^F => (T|F)&(T^F), You can see, starts from i = 1 & k moves 2 steps k += 2
for(k = i + 1; k <= j - 1; k += 2)
==============================*/

int booleanParenthesis(string input, int i, int j, bool isTrue = true) {
	// STEP 2: Base condition
	if(i > j)
		return 0;
	if(i == j) {
		if(isTrue)
			return input[i] == 'T' ? 1 : 0;
		else
			return input[i] == 'F' ? 1 : 0;
	}

	// STEP 3: Find K-loop k -> i to j
	int answer = 0;	

	for(int k = i + 1; k < j; k += 2) {
		// get recursive solutions of sub-problems
		int lt = booleanParenthesis(input, i, k - 1, true);
		int lf = booleanParenthesis(input, i, k - 1, false);
		int rt = booleanParenthesis(input, k + 1, j, true);
		int rf = booleanParenthesis(input, k + 1, j, false);

		// calcuate answer from temporary answers

		if(input[k] == '&') {
			if(isTrue == true) {
				answer += lt * rt;
			} else if(isTrue == false) {
				answer += lt * rf + lf * rt + lf * rf;
			}
		} else if(input[k] == '|') {
			if(isTrue == true) {
				answer += lt * rt + lt * rf + lf * rt;
			} else if(isTrue == false) {
				answer += lf * rf;
			}
		} else if(input[k] == '^') {
			if(isTrue == true) {
				answer += lf * rt + lt * rf;
			} else if(isTrue == false) {
				answer += lf * rf + lt * rt;
			}
		}
	}

	return answer;
}

// memiozed with 3D DP 
int dp[101][101][2];
int booleanParenthesisMemoized(string input, int i, int j, int isTrue = 1) {
	if(dp[i][j][isTrue] != -1)
		return dp[i][j][isTrue];
	if(i > j)
		return 0;
	if(i == j) {
		if(isTrue == 1) {
			return dp[i][j][isTrue] = input[i] == 'T' ? 1 : 0;
		} else if(isTrue == 0){
			return dp[i][j][isTrue] = input[i] == 'F' ? 1 : 0;
		}
	}

	int ans = 0;
	for(int k = i + 1; k < j; ++k) {
		int lt, rt, lf, rf;

		// left true
		if(dp[i][k - 1][1] != -1) {
			lt = dp[i][k - 1][1];
		} else {
			lt = booleanParenthesisMemoized(input, i, k - 1, 1);
			dp[i][k - 1][1] = lt;
		}

		// left false
		if(dp[i][k - 1][0] != -1) {
			lf = dp[i][k - 1][0];
		} else {
			lf = booleanParenthesisMemoized(input, i, k - 1, 0);
			dp[i][k - 1][0] = lf;
		}

		// right true
		if(dp[k + 1][j][1] != -1) {
			rt = dp[k + 1][j][1];
		} else {
			rt = booleanParenthesisMemoized(input, k + 1, j, 1);
			dp[k + 1][j][1] = rt;
		}

		// right false
		if(dp[k + 1][j][0] != -1) {
			rf = dp[k + 1][j][0];
		} else {
			rf = booleanParenthesisMemoized(input, k + 1, j, 0);
			dp[k + 1][j][0] = rf;
		}

		// calcuate final anser
		if(input[k] == '&') {
			if(isTrue == true) {
				ans += lt * rt;
			} else if(isTrue == false) {
				ans += lt * rf + lf * rt + lf * rf;
			}
		} else if(input[k] == '|') {
			if(isTrue == true) {
				ans += lt * rt + lt * rf + lf * rt;
			} else if(isTrue == false) {
				ans += lf * rf;
			}
		} else if(input[k] == '^') {
			if(isTrue == true) {
				ans += lf * rt + lt * rf;
			} else if(isTrue == false) {
				ans += lf * rf + lt * rt;
			}
		}
	}

	return dp[i][j][isTrue] = ans;
}

unordered_map<string, int> mp;
int booleanParenthesisMemoizedMap(string input, int i, int j, bool isTrue = true) {
	if(i > j)
		return 0;
	if(i == j) {
		if(isTrue == true) {
			return input[i] == 'T';
		} else {
			return input[i] == 'F';
		}
	}

	string tmp = to_string(i) + "_" + to_string(j) + "_" + (isTrue ? "T" : "F");
	if(mp.find(tmp) != mp.end())
		return mp[tmp];

	int ans = 0;
	for(int k = i + 1; k < j; ++k) {
		int lt, rt, lf, rf;

		string checkLt = to_string(i) + "_" + to_string(k - 1) + "_" + "T";
		string checkLf = to_string(i) + "_" + to_string(k - 1) + "_" + "F";
		string checkRt = to_string(k + 1) + "_" + to_string(j)  + "_" + "T";
		string checkRf = to_string(k + 1) + "_" + to_string(j)  + "_" + "F";

		// // left true
		if(mp.find(checkLt) != mp.end()) {
			lt = mp[checkLt];
		} else {
			lt = booleanParenthesisMemoizedMap(input, i, k - 1, 1);
			mp[checkLt]  = lt;
		}

		// // left false
		if(mp.find(checkLf) != mp.end()) {
			lf = mp[checkLf];
		} else {
			lf = booleanParenthesisMemoizedMap(input, i, k - 1, 1);
			mp[checkLf]  = lf;
		}


		// // right true
		if(mp.find(checkRt) != mp.end()) {
			rt = mp[checkRt];
		} else {
			rt = booleanParenthesisMemoizedMap(input, k + 1, j, 1);
			mp[checkRt] = rt;
		}

		// // right false
		if(mp.find(checkRf) != mp.end()) {
			rf = dp[k + 1][j][0];
		} else {
			rf = booleanParenthesisMemoizedMap(input, k + 1, j, 0);
			mp[checkRf] = rf;
		}

		// // calcuate final answer
		if(input[k] == '&') {
			if(isTrue == true) {
				ans += lt * rt;
			} else if(isTrue == false) {
				ans += lt * rf + lf * rt + lf * rf;
			}
		} else if(input[k] == '|') {
			if(isTrue == true) {
				ans += lt * rt + lt * rf + lf * rt;
			} else if(isTrue == false) {
				ans += lf * rf;
			}
		} else if(input[k] == '^') {
			if(isTrue == true) {
				ans += lf * rt + lt * rf;
			} else if(isTrue == false) {
				ans += lf * rf + lt * rt;
			}
		}
	}

	return mp[tmp] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input = "T|F&T^F";
	// STEP 1: Choose i, j end indexes
	int i = 0, j = input.length() - 1;
	cout << booleanParenthesis(input, i, j) << '\n';

	input = "T|F&T";
	i = 0, j = input.length() - 1;
	cout << booleanParenthesis(input, i, j) << '\n';

	memset(dp, -1, sizeof(dp));

	input = "T|F&T^F";
	// STEP 1: Choose i, j end indexes
	i = 0, j = input.length() - 1;
	cout << booleanParenthesisMemoized(input, i, j) << '\n';

	input = "T|F&T";
	i = 0, j = input.length() - 1;
	cout << booleanParenthesisMemoized(input, i, j) << '\n';

	// solution using DP Table + Map (for reducing dimension of DP Table)
	// memset(T, -1, sizeof(T));
	mp.clear();
	input = "T|F&T^F";
	// STEP 1: Choose i, j end indexes
	i = 0, j = input.length() - 1;
	cout << booleanParenthesisMemoizedMap(input, i, j) << '\n';

	input = "T|F&T";
	i = 0, j = input.length() - 1;
	cout << booleanParenthesisMemoizedMap(input, i, j) << '\n';
	
	return 0;
}