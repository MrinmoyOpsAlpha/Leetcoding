class Solution {
public:
    
     long long getSumOfFactors(int n){
        int divisor = 2;
        long long ans = 0;
         while(n>1){
             if(n % divisor ==0){
                 ans = ans + divisor;
                 n = n/divisor;
             }
             else divisor++;
         }
         return ans;
     }
    
    int smallestValue(int n) {
        while(true){
            long long sum = getSumOfFactors(n);
            if (n==sum) break;
            n = sum ;
        }
        return n;
    }
};