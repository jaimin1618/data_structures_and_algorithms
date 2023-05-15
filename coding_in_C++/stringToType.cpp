#include<bits/stdc++.h>
using namespace std;

template <typename T>
T convert(const string& s) {
   stringstream ss(s);
   T t;
   ss >> t;
   return t;
}

int main() {
   cout << (convert<float>("10.75")+100) << '\n';
   priority_queue<int> pq;
   return 0;
}