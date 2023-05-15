#include<bits/stdc++.h>

int minWayToEvaluateExpressionTrue(std::string s, int i, int j, bool isTrue) {
	if(i > j) 
		return 0;
	if(i == j) {
		if(isTrue == true) return s[i] == 'T';
		else return s[i] == 'F';
	}

	int ans = 0;
	for(int k = i + 1; k < j; k += 2) {
		int LT, LF, RT, RF;
		LT = minWayToEvaluateExpressionTrue(s, i, k - 1, true);
		LF = minWayToEvaluateExpressionTrue(s, i, k - 1, false);
		RT = minWayToEvaluateExpressionTrue(s, k + 1, j, true);
		RF = minWayToEvaluateExpressionTrue(s, k + 1, j, false);

		if(s[k] == '&') {
			if(isTrue == true) ans += LT * RT;
			else ans += LF * RT + LF * RF + LT * RF;
		} else if(s[k] == '|') {
			if(isTrue == true) ans += LT * RT + LT * RF + LF * RT;
			else ans += LF * RF;
		} else if(s[k] == '^') {
			if(isTrue == true) ans += LF * RT + LT * RF;
			else ans += LT * RT + LF * RF;
		}
	}

	return ans;
}

std::unordered_map<std::string, int> mp;
int minWayToEvaluateExpressionTrueMemoized(std::string s, int i, int j, bool isTrue) {
	std::string tmps = 
		std::to_string(i) + "_" + 
		std::to_string(j) + "_" + 
		(isTrue ? "T" : "F");
	if(mp.find(tmps) != mp.end()) 
		return mp[tmps];
	if(i > j) 
		return mp[tmps] = 0;
	if(i == j) {
		if(isTrue == true) return mp[tmps] = s[i] == 'T';
		else return mp[tmps] = s[i] == 'F';
	}

	int ans = 0;
	for(int k = i + 1; k < j; k += 2) {
		int LT, LF, RT, RF;
		LT = minWayToEvaluateExpressionTrue(s, i, k - 1, true);
		LF = minWayToEvaluateExpressionTrue(s, i, k - 1, false);
		RT = minWayToEvaluateExpressionTrue(s, k + 1, j, true);
		RF = minWayToEvaluateExpressionTrue(s, k + 1, j, false);

		if(s[k] == '&') {
			if(isTrue == true) ans += LT * RT;
			else ans += LF * RT + LF * RF + LT * RF;
		} else if(s[k] == '|') {
			if(isTrue == true) ans += LT * RT + LT * RF + LF * RT;
			else ans += LF * RF;
		} else if(s[k] == '^') {
			if(isTrue == true) ans += LF * RT + LT * RF;
			else ans += LT * RT + LF * RF;
		}
	}

	return mp[tmps] = ans;
}



int main() {
	// string can contain T, F, &, |, ^
	// find ways such that expression evaluates to TRUE
	// std::string exp = "T^F&T";
	std::string exp = "T|F&T^F";
	mp.clear();
	std::cout << minWayToEvaluateExpressionTrue(exp, 0, exp.length() - 1, true);
	std::cout << '\n';
	std::cout << minWayToEvaluateExpressionTrueMemoized(exp, 0, exp.length() - 1, true);
	std::cout << '\n';

	return 0;
}