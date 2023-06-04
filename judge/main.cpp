#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegative(vector<int>& v, int k) {
    const int n = v.size();
    vector<int> op;
    list<int> negatives;
    vector<int> output;

    int i = 0, j = 0;

    while(j < n) {
        if(v[j] < 0)
            negatives.push_back(v[j]);

        if(j - i + 1 < k) {
            ++j;
        } else if(j - i + 1 == k) {
            // we find our answer when window size condition is hit
            if(negatives.empty()) 
                output.push_back(0);
            else 
                output.push_back(negatives.front());

            if(!negatives.empty() && negatives.front() == v[i])
                negatives.pop_front();

            ++i;
            ++j;
        }
    }

    return output;
} 

int main() {
    vector<int> v {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    for(auto& el: firstNegative(v, k))
        cout << el << ' ';
    cout << '\n';

    
    return 0;
}