#include<bits/stdc++.h>
using namespace std;

/**
 * Example: 
 * plain: forxxorfxdofr
 * pat: for
 * 
 * output: count = 3
 */

int countAnagrams(string s, string pat) {
	const int n = s.length();
	const int m = pat.length(); // pattern size m = window size K
	int anagramCount = 0;

	unordered_map<char, int> patMp;
	for(auto& el: pat) 
		patMp[el]++;
	int count = patMp.size();

	int i = 0, j = 0;
	while(j < n) {
		if(patMp.find(s[j]) != patMp.end())
			patMp[s[j]]--;

		if(patMp[s[j]] == 0)
			count--;

		if(j - i + 1 < m) {
			++j;
		} else if(j - i + 1 == m) {
			if(count == 0) {
				++anagramCount;
			} 

			patMp[s[i]]++;
			++i;
			++j;
		}
	}
	
	return anagramCount;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string plain = "FORXXORFXDOFR";
	string pat = "FOR";
	/**
	 * count number of anagrams of pat "fox" string in plain string 
	 */
	cout << countAnagrams(plain, pat) << '\n';

	plain = "aabaabaa";
	pat = "aaba";
	cout << countAnagrams(plain, pat) << '\n';	

	return 0;
}