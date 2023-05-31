#include<bits/stdc++.h>
using namespace std;

/**
 * NOTE: This  Another pattern for Heap based problems
 * there are many problems similar to this
 * 
 * Important Concept: 
 * in this types of problems we usually use property of heap that is 
 * "MAX/MIN element in top of heap"
 * 
 * See this question on LeetCode: 
 * https://leetcode.com/problems/last-stone-weight/
 * in this question, they have explicitly said take "2 HEAVIEST stones"
 * how to pick heaviest element without running loop for finding max and such
 * 
 * simple, we make MaxHeap. So that each time we select element it is the heaviest
 * and then pop. You will know what to do after that easy! 
 * 
 * But in this category of question, sometimes they won't tell you select 2 or 3 heaviest/smallest or anything
 * you would have to find the way of that
 * 
 * See, this question to understand more
 * 
 * Another Important Concept, 
 * 
 * In these problems, when you select 2 MIN length ropes, you join them, find the cose of joining
 * after that you have to push resultant rope (final rope after operation) back into Max-Heap. 
 * You will perform this till there is not rope or only 1 rope remain in Max-Heap
 */

int connectRopesForMinimumCost(vector<int>& rope_lengths) {
	priority_queue<int, vector<int>, greater<int>> minH;
	int cost = 0;

	for(auto& el: rope_lengths) 
		minH.push(el);

	while(minH.size() > 1) {
		int first = minH.top();
		minH.pop();
		int second = minH.top();
		minH.pop();
		int result = first + second;
		cost += result;
		minH.push(result);
	} 

	return cost;
}

int main() {
	vector<int> rope_lengths {1, 2, 3, 4, 5};
	cout << "Min cost: " << connectRopesForMinimumCost(rope_lengths) << '\n';

	return 0;
}