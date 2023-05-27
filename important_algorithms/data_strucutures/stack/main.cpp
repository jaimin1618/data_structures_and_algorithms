#include<bits/stdc++.h>
using namespace std;

/**
 * Indentification of Stack problems
 * 1. Problem related to Array or String
 * 2. (most imp identification) Topical iterative soluion of these problem involving would be O(N^2)
 * where second (j loop) will be dependent on first (i loop) in any of following manners
 * i from i to n, 
 * then
 * 	   j from 0 to i, ++j
 *     j from i to 0, --j
 *     j from i to n, ++j
 *     j from n to j, --j
 * 
 * If you find these patterns in Array/String problem or any problems
 * there are high chances you can solve this in O(n) using Stack
 * 
 * In nutshell, if you written brute force solution and in that solution your
 * second (j loop) is dependent of first (i loop) or j = f(i)
 * then it can be solved in using Stack data strucuture in O(N)
 * There are 100% chances that you can optimize to O(N) using Stack
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    

    return 0;
}