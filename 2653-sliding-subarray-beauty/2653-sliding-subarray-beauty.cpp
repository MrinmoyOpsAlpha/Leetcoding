class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> res;
        map<int,int> mp;
        
        int i=0, j =0;
        
        while(j<nums.size()){
            mp[nums[j]]++;
            
            if(j-i+1 == k){
                int count = 0;
                int beauty = 0;
                
                for(auto it:mp){
                    if(it.first < 0){
                        count += it.second;
                    }
                    
                    if(count >= x){
                        beauty = it.first;
                        break;
                    }
                }
                
                if(count >= x){
                    res.push_back(beauty);
                }
                else{
                    res.push_back(0);
                }
                
                mp[nums[i]]--;
                if(mp[nums[i]] ==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        
        return res;
    }
};