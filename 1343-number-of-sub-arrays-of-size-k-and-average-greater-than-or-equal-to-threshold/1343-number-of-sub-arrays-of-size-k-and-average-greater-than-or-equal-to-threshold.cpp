class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, cnt = 0;
        
        int i = 0, j =0;
        while(j<arr.size()){
            sum = sum + arr[j];
            if(j-i+1 == k){
                if(sum / k >= threshold) cnt++;
                sum = sum - arr[i];
                i++;
                j++;                
            }
            else
                j++;
        }
        return cnt;
    }
};