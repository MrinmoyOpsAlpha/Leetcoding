class MinStack {
public:
    vector<pair<int,int>> v;
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.size()==0) 
            v.push_back({val,val});
        else
            v.push_back({val, min(v.back().second, val)});
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */