class MedianFinder {
    priority_queue<long> small;
    priority_queue<long,vector<long>,greater<long>>large;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        
        if(!small.empty() && !large.empty() && small.top() > large.top()){
            large.push(small.top());
            small.pop();
        }
        
        if(small.size() > large.size() + 1){
            large.push(small.top());
            small.pop();
        }
        
        if(large.size() > small.size() + 1){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) return small.top();
        else if(small.size() < large.size()) return large.top();
        else return (small.top() + large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */