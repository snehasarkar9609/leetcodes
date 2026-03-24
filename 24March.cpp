class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),mod=12345;
        vector<vector<int>>ans(n,vector<int>(m));
        long long pref=1,suff=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=pref;
                pref=(pref*grid[i][j])%mod;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j]=(ans[i][j]*suff)%mod;
                suff=(suff*grid[i][j])%mod;
            }
        }
        return ans;
    }
};


class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<vector<int>>adj(n);
        vector<int>inDegree(n);
        for(int i = 0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i = 0;i<inDegree.size();i++){
            if(inDegree[i])continue;
            q.push(i);
        }
        int cnt = 0;
        while(q.size()){
            auto elem = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[elem]){
                inDegree[it]--;
                if(inDegree[it])continue;
                q.push(it);
            }
        }
        return cnt == n;
    }
};