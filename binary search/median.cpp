#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

// Function to compute running medians
vector<int> runningMedians(vector<int> arr) {
    // Max-heap to store the smaller half of the numbers
    priority_queue<int> maxHeap;
    // Min-heap to store the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;

    vector<int> medians;

    for (int num : arr) {
        // Insert the number into one of the heaps
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Compute the median
        if (maxHeap.size() > minHeap.size()) {
            medians.push_back(maxHeap.top());
        } else {
            medians.push_back(maxHeap.top()); // Since the heaps are balanced, maxHeap will have the median
        }
    }

    return medians;
}

int main() {
    vector<int> arr = {8, 2, 11, 9, 5};
    vector<int> result = runningMedians(arr);
    
    cout << "Medians: ";
    for (int median : result) {
        cout << median << " ";
    }
    cout << endl;

    return 0;
}
