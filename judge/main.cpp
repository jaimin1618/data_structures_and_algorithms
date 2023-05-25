#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& v) {
    int n = v.size();
    int L = 0, R = n - 1;

    while(L <= R) {
        int mid = L + (R - L) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        cout << v[prev] << " = " << v[mid] << " = " << v[next] << '\n';

        if(v[mid] < v[prev] && v[mid] < v[next])
            return v[mid];
        else if(v[0] <= v[mid])
            L = mid + 1;
        else if(v[mid] <= v[n - 1])
            R = mid - 1;
    }

    return min(v[0], v[n - 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v {11,13,15,17};
    cout << findMin(v) << '\n';
    

    return 0;
}