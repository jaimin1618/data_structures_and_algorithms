#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x = 0;
    int MOD = 8;

    cout << (x - 1 % 8) << '\n';
    // IMPORTANT: DO NOT FORGOT "(" ")" when doing modulo of negative numbers
    cout << ((x + MOD - 1) % MOD) << '\n';
    

    return 0;
}