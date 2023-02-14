class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long int low=1,high=INT_MAX;
        int ans =INT_MAX;
        
       long long int lcm=((long long)divisor1*divisor2)/__gcd(divisor1,divisor2);
        
        while(low<=high){
            int mid = (low + high) >> 1;
            
            int not_d1 = mid - (mid / divisor1);
            int not_d2 = mid - (mid / divisor2);
            int not_both = mid - (mid / lcm);
            
            if(not_d1 >= uniqueCnt1 && not_d2 >= uniqueCnt2 && not_both >= (uniqueCnt1 + uniqueCnt2)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};