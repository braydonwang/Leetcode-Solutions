class MedianFinder {
private:
    priority_queue<int> fst;
    priority_queue<int,vector<int>,greater<int>> sec;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (fst.empty() || num > fst.top()) {
            sec.push(num);
        } else {
            fst.push(num);
        }
        if (fst.size() == sec.size() + 2) {
            int temp = fst.top(); fst.pop();
            sec.push(temp);
        } else if (fst.size() + 2 == sec.size()) {
            int temp = sec.top(); sec.pop();
            fst.push(temp);
        }
    }
    
    double findMedian() {
        if (fst.size() == sec.size()) {
            double ret = (fst.top() + sec.top()*1.0) / 2.0;
            return ret;
        } else if (fst.size() > sec.size()) {
            return fst.top();
        } else {
            return sec.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */