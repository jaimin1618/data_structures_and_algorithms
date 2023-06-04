#include<bits/stdc++.h>
using namespace std;

vector<int> getLeftCount(string s) {
    const int n = s.length();
    unordered_map<char, int> mp;
    vector<int> leftCount(n);

    for(int i = 0; i < n; ++i) {
        if(mp.find(s[i]) != mp.end()) {
            leftCount[i] = mp[s[i]];
        } else {
            mp[s[i]] = 0;
            leftCount[i] = mp[s[i]];
        }

        mp[s[i]]++;
    }

    return leftCount;
}

vector<int> getRightCount(string s) {
    const int n = s.length();
    unordered_map<char, int> mp;
    vector<int> rightCount(n);

    for(int i = n - 1; i >= 0; --i) {
        if(mp.find(s[i]) != mp.end()) {
            rightCount[i] = mp[s[i]];
        } else {
            mp[s[i]] = 0;
            rightCount[i] = mp[s[i]];
        }

        mp[s[i]]++;
    }

    return rightCount;
}

int minimizedStringLength(string s) {
    const int n = s.length();
    vector<int> lCount = getLeftCount(s);
    vector<int> rCount = getRightCount(s);
    int mnLength = numeric_limits<int>::max();

    for(int i = 0; i < n; ++i) {
        int length;

        if(lCount[i] != 0 && rCount[i] != 0) {
            int op = min(lCount[i], rCount[i]) * 2;
            length = n - op;
        } else if(lCount[i] != 0 || rCount[i] != 0) {
            length = n - 1;
        }

        mnLength = min(length, mnLength);
    }        

    return mnLength;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const string ip = "dddaaa";
    int result = minimizedStringLength(ip);
    cout << result << '\n';

    

    return 0;
}