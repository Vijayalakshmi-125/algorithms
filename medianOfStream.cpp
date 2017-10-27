/*

https://leetcode.com/problems/find-median-from-data-stream/

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.

*/

class MedianFinder {
public:
    priority_queue<int> maxHeap; // stores numbers that are to the left of midpoint
    priority_queue<int, vector<int>, greater<int>> minHeap; // stores to the right of midpoint
    int n = 0;
    MedianFinder() {

    }
    
    void addNum(int num) {
        
        if (++n / 2 > maxHeap.size()) {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (!maxHeap.empty() && num < maxHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.push(num);
            maxHeap.pop();
        }
        else {
            minHeap.push(num);
        }
    }
    
    double findMedian() {
        return n % 2 ? minHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0;
    }
};