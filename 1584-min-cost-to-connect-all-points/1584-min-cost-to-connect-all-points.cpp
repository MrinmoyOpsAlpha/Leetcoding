class DisjointSet{
    vector<int> parent,size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i] = 1;
            }
        }
    
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> edges;
        int n = points.size();
        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({wt,{i,j}});
            }
        
        sort(edges.begin(),edges.end());
        DisjointSet ds(n);
        int mstWt = 0;
        
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u)!= ds.findUPar(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        
        return mstWt;
    }
};