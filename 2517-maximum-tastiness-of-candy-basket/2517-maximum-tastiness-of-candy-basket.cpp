class Solution {
public:
    
    bool canPlaceCandy(vector<int>& price,int n, int k, int dist){
        int count = 1;
        int co_ord = price[0];
        
        for(int i=1;i<n;i++){
            if(price[i] - co_ord >= dist){
                count++;
                co_ord = price[i];
            }
            if(count == k) return true;
        }
        return false;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(),price.end());
        
        int low = 1, high = price[n-1]-price[0];
        int ans = 0;
        
        while(low<=high){
            int mid = (low + high) >> 1;
            if(canPlaceCandy(price,n,k,mid)){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        
        return ans;
    }
};