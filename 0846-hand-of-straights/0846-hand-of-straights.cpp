class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int, int> mp;
        for(auto i: hand) mp[i]++;
        
         while(mp.size()){
            int first = mp.begin() -> first;  
           
            int target = first + groupSize - 1;
            
            for(int i = first; i <= target; i++){
                
                if(mp.count(i) == 0) return false;  
                
                else if(--mp[i] == 0) mp.erase(i);  
            }        
        }
        
        return true;
    }
};