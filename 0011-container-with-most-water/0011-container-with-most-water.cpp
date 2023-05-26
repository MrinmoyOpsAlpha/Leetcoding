class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        
        int water = 0;
        while(i<j){
            int h = min(height[i],height[j]);
            water = max(water,(j-i)*h);
            while(i<j && height[i]<=h) i++;
            while(i<j && height[j]<=h) j--;
        }
        return water;
    }
};