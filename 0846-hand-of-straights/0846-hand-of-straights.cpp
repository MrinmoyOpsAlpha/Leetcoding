class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int, int> mp;
        for(auto i: hand) mp[i]++;
        
        while(mp.size()){
            int curr = mp.begin()->first;
            
            for(int i=0;i<groupSize;i++){
                if(mp.find(curr + i) == mp.end()) return false;
                
                mp[curr + i]--;
                
                if(mp[curr + i] == 0) mp.erase(curr + i);
            }
        }
        
        return true;
    }
};