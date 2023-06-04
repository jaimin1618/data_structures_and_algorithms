#include<bits/stdc++.h>
using namespace std;

long long matrixSumQueries(int n, vector<vector<int>>& queries) {
    long long sum = 0;
    vector<vector<int>> mat (n, vector<int>(n, 0));

    for(auto& query: queries) {
        int tp = query[0];
        int idx = query[1];
        int v = query[2];

        int prevSum = 0;
        int currSum = 0;

        if(tp == 0) {
            for(int i = 0; i < n; ++i) {
                prevSum += mat[idx][i];
                mat[idx][i] = v;
                currSum += mat[idx][i];
            }
        } else if(tp == 1) {
            for(int i = 0; i < n; ++i) {
                prevSum += mat[i][idx];
                mat[i][idx] = v;
                currSum += mat[i][idx];
            }
        }

        sum -= prevSum;
        sum += currSum;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> q {
        {0,0,4},{0,1,2},{1,0,1},{0,2,3},{1,2,1}
    };
    int n = 3;
    cout << matrixSumQueries(n, q) << '\n';

    

    return 0;
}