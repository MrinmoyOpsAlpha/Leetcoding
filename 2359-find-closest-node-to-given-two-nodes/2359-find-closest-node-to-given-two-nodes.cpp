class Solution {
public:
int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        vector<int>dist1(edges.size(),-1);
        vector<int>dist2(edges.size(),-1);
        
        vector<bool>visited(edges.size(),false);
        dfs(node1,dist1,visited,edges,0);
        visited.assign(edges.size(),false);
        dfs(node2,dist2,visited,edges,0);
        
        int ans = edges.size();
        int result = -1;
         for(int i=0;i<edges.size();i++)
         {  
             if(dist1[i]!=-1 && dist2[i]!=-1)
             {
                if(max(dist1[i] , dist2[i]) < ans)
                {
                    ans = max(dist1[i] , dist2[i]);
                    result = i;
                }
             }
         }
        return result;
       
    }
    
      void dfs(int node, vector<int>&dist1, vector<bool>&visited,vector<int>& edges, int distance)
      {          
           if(node!=-1 && !visited[node] )
           {  visited[node] = true;
              dist1[node] = distance;
             dfs(edges[node], dist1, visited, edges, distance+1);
           }
      }

};