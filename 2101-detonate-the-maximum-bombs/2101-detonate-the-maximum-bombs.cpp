class Solution {
    void dfs(int src, vector<int>& vis, vector<int> adj[]) {
        vis[src] = 1;
        for (auto x : adj[src]) {
            if (!vis[x]) {
                dfs(x, vis, adj);
            }
        }
    }

public:
    typedef long long ll;
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++) {
            ll r = bombs[i][2];
            ll x = bombs[i][0];
            ll y = bombs[i][1];

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    ll r2 = bombs[j][2];
                    ll x2 = bombs[j][0];
                    ll y2 = bombs[j][1];

                    ll dist = (x - x2) * (x - x2) + (y - y2) * (y - y2);
                    if (dist <= r * r) {
                        adj[i].push_back(j);
                    }
                }
            }
        }

        vector<int> vis(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            dfs(i, vis, adj);

            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (vis[j] == 1) {
                    cnt++;
                }
            }

            ans = max(cnt, ans);

            fill(vis.begin(), vis.end(), 0);
        }

        return ans;
    }
};
