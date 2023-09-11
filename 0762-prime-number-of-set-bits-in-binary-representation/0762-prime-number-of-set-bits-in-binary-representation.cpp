class Solution {
    bool isprime(int n){
        if(n<=1) return false;
        
        for(int i=2;i<=n/2;i++){
            if(n%i == 0) return false;
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int countPrime = 0;
        
        for(int i=left;i<=right;i++){
            int countSetBits = 0;
            int n = i;
            while(n){
                countSetBits += (n%2);
                n = n>>1;
            }
            
            countPrime += isprime(countSetBits) ? 1 : 0;
        }
        
        return countPrime;
    }
};