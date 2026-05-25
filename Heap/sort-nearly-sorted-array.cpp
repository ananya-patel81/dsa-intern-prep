#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort a k-sorted array using a min heap
    vector<int> sortNearlySortedArray(vector<int>& arr, int k) {
        // Create a min heap using priority_queue with greater comparator
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Store the final sorted result
        vector<int> result;

        // Push first k+1 elements into the heap
        for (int i = 0; i <= k && i < arr.size(); i++) {
            minHeap.push(arr[i]);
        }

        // Process the remaining elements of the array
        for (int i = k + 1; i < arr.size(); i++) {
            // Push the smallest element from the heap to the result
            result.push_back(minHeap.top());
            minHeap.pop();

            // Push the current element into the heap
            minHeap.push(arr[i]);
        }

        // Pop remaining elements from the heap
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        // Return the sorted array
        return result;
    }
};
