#include<bits/stdc++.h>
using namespace std;

/*====================================
why to think Sliding window here?

condition to pick toys were: 
 1> You have to pick toys continuously
 2> You can only pick 2 categories of toys at a time

Here, continuous (sub-string / sub-array) identifies Sliding window
secondly, our solution is number of picked toys which is SIZE OF WINDOW having max 2 categories. 
if this is understood that when condition of 2 category hit we will have one possible/candidate solution
then you can think of whole picture and write your solution using Sliding window algorithm
=====================================*/

// how to think solution
int pickToys(string s) {
	const int n = s.length();
	int i = 0, j = 0;
	int maxToys = numeric_limits<int>::min();
	unordered_map<char, int> mp;
	const int MAX_CATEGORIES_SELECT = 2;

	while(j < n) {
		mp[s[j]]++;

		int numOfSelectedCategories = mp.size();

		if(numOfSelectedCategories == MAX_CATEGORIES_SELECT) {
			int k = j - i + 1; // window size, or number of selected toys
			maxToys = max(maxToys, k);
			++j;

		} else if(numOfSelectedCategories < MAX_CATEGORIES_SELECT) {
			++j;

		} else {
			while(numOfSelectedCategories > MAX_CATEGORIES_SELECT) {
				mp[s[i]]--;
				if(mp[s[i]] == 0)
					mp.erase(mp.find(s[i]));
				numOfSelectedCategories = mp.size();
				++i;
			}
		}
	}

	return maxToys;
}

// how to write solution
int pickToysSoluiton(string s) {
	const int n = s.length();
	int i = 0, j = 0;
	int mx = numeric_limits<int>::min();
	const int MAX_CAT = 2;
	unordered_map<char, int> mp;

	while(j < n) {
		mp[s[j]]++;
		int selectedCat = mp.size();

		if(selectedCat == MAX_CAT) {
			int k = j - i + 1;
			mx = max(mx, k);

		} else if(selectedCat > MAX_CAT) {
			mp[s[i]]--;
			if(mp[s[i]] == 0)
				mp.erase(mp.find(s[i]));
			selectedCat = mp.size();
			++i;
		}

		++j;
	}

	return mx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string ip = "abaccab"; // each letter indicates type of toy
	cout << pickToys(ip) << '\n';
	cout << pickToysSoluiton(ip) << '\n';



	return 0;
}