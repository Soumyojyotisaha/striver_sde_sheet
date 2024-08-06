#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);
        // Ensure all elements in maxHeap are smaller than all in minHeap
        if (!minHeap.empty() && !maxHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // Balance the sizes of the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() const {
        if (minHeap.size() > maxHeap.size()) return minHeap.top();
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder* obj = new MedianFinder();
    
    obj->addNum(1);
    cout << "Median after adding 1: " << obj->findMedian() << endl;
    
    obj->addNum(2);
    cout << "Median after adding 2: " << obj->findMedian() << endl;
    
    obj->addNum(3);
    cout << "Median after adding 3: " << obj->findMedian() << endl;
    
    obj->addNum(4);
    cout << "Median after adding 4: " << obj->findMedian() << endl;
    
    obj->addNum(5);
    cout << "Median after adding 5: " << obj->findMedian() << endl;
    
    delete obj;
    return 0;
}
