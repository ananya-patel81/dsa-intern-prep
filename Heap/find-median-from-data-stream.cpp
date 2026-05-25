class MedianFinder {
private:
    //initializing the maxHeap;
    priority_queue<int> maxHeap;
    //initializing the minHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num<maxHeap.top()) maxHeap.push(num);
        else{
            minHeap.push(num);
        }
    }
    
    double findMedian() {
        while(maxHeap.size() > minHeap.size() + 1 || minHeap.size() > maxHeap.size() + 1){
            if(maxHeap.size()>minHeap.size()){
                int temp=maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            }
            else{
                int temp=minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);

            }
        }

        if (maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top()) / 2.0; 
        }
    
    // Otherwise, the heap with more elements holds the median.
    // (Assuming your addNum logic keeps maxHeap larger or equal)
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
