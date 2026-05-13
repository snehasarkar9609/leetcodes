class Solution {
  public:
    
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> visited(V, 0);
        
        int candidate = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                
                candidate = i;
            }
        }

        fill(visited.begin(), visited.end(), 0);

        dfs(candidate, adj, visited);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return -1;
            }
        }

        return candidate;
    }
};



vector<int> rotateArray(vector<int>& arr, int n){
	int temp=arr[0];
	for(int i=1;i<n;i++){
		arr[i-1]=arr[i];
	}
	arr[n-1]=temp;
	return arr;
}

vector rotateRight(int arr[], int n, int k){
	if(n==0) return ;
	k=k%n;
	int temp[k];
	for(int i=n-k;i<n;i++){
		temp[i-n-k]=arr[k];
	}
	for(int i=n-k-1;i>=0;i--){
		arr[i-k]=arr[i];
	}
	for(int i=0;i<k;i--){
		arr[i]=temp[i];
	}
}

class Solution {
	public:
		vector<int> debug
};