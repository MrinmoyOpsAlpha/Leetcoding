class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> visited(1001,false);
        int ans = 0;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                
                if(node == goal) return ans;
                
                if(node > 1000 || node<0 || visited[node]) continue;
                
                visited[node] = true;
                
                for(auto it:nums){
                    int a = node + it;
                    int b = node - it;
                    int c = node ^ it;
                    
                    for(auto j:{a,b,c}){
                        q.push(j);
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};