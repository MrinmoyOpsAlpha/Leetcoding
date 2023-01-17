class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips=0,counter=0;
        
        for(auto it:s){
            if(it=='0'){
                flips++;
            }else{
                counter++;
            }
            flips = min(flips,counter);
        }
        return flips;
    }
};