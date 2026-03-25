#include<iostream>
using namespace std;
class Solution{
	public:
		int countSubstring(string s, char c){
			int count=0;
			int currLength=0;
			for(char ch:s){
				if(ch==c) currLength++;
			else{
				count+=(currentLength*(currentLength+1))/2;
				currentLength=0;
			}
		}
		count+=(currentLength*(currentLength+1))/2;
		return count;
	}
		
};

int main(){
	string s;
	char c;
	cin>>s>>c;
	Solution obj;
	cout<<obj.countSubstring(s,c)<<endl;
	return 0;
}

class Solution{
	public:
		typedef long long ll;
		bool canPartitionGrid(vector<vector<int>>& grid){
			int m=grid.size();
			int n=grid[0].size();
			vector<ll> rowSum(m,0);
			vector<ll> colSum(n,0);
			ll total=0;
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					total+=grid[i][j];
					rowSum[i]+=grid[i][j];
					colSum[j]+=grid[i][j];
				}
			}
			if(total%2!=0) return false;
			ll upper=0;
			for(int i=0;i<m-1;i++){
				upper+=rowSum[i];
				if(upper==total-upper){
					return true;
				}
			}
			ll left=0;
			for(int i=0;i<n-1;i++){
				left+=colSum[j];
				if(left==total-left) return true;
			}
			return false;
		}
};


class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        vector<int>degree(V,0);
        
        for(auto &e:edges)
        {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
            
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        
        queue<int>q;
        
        for(int i = 0; i < V; i++) {
            if(degree[i] == 1) {
                q.push(i);
            }
        }
        
        int rem=V;
        
        
        while(rem>2)
        {
            int size=q.size();
            
            rem-=size;
            while(size--){
                
                int first=q.front();q.pop();
                
            for(auto &child:adj[first])
            {
                degree[child]--;
                    if(degree[child] == 1) {
                        q.push(child);
                    }
            }
                
                
            }
            
            
        }
        
           vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};



