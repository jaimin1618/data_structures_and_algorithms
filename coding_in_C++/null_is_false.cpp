#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int *p = NULL;
    if(p) {
        cout << "NULL is not evaluated False" << '\n';
    } else {
        // this will be printed
        cout << "NULL is evaluated False" << '\n';
    }

    return 0;
}