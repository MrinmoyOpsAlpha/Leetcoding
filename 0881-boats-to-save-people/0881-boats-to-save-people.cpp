class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int minBoats = 0;
        int i = 0, j = people.size()-1;
        while(i<=j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            }
            else j--;
            minBoats++;
        }
        return minBoats;
    }
};