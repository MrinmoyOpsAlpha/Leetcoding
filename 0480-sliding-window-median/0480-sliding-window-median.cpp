class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        
        set<pair<int, int>> minHeap;
        set<pair<int, int>, greater<pair<int, int>>> maxHeap;
        
        int i = 0, j = 0, n = nums.size();
        while(j < n){
            maxHeap.insert({nums[j],j});
            minHeap.insert({maxHeap.begin()->first, maxHeap.begin()->second});
            maxHeap.erase(maxHeap.begin());
            
            if(minHeap.size() > maxHeap.size()){
                maxHeap.insert({minHeap.begin()->first, minHeap.begin()->second});
                minHeap.erase(minHeap.begin());
            }
            
            if(j-i+1 == k){
                if(k&1) ans.push_back(maxHeap.begin()->first);
                else{
                    ans.push_back((0ll + maxHeap.begin()->first + minHeap.begin()->first + 0.0)/2.0);
                }
                
                if(maxHeap.count({nums[i], i})) maxHeap.erase(maxHeap.find({nums[i], i}));
                if(minHeap.count({nums[i], i})) minHeap.erase(minHeap.find({nums[i], i}));
                i++;
            }
            j++;
        }
        return ans;
    }
};