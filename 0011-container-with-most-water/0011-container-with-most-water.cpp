class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int water = 0;
        
        while(i<j){
            int h = min(height[i],height[j]);
            water = max(water,(j-i) * h);            
            while(i<j && height[i] <= h) i++;
            while(i<j && height[j] <= h) j--;
        }
        return water;
    }
};