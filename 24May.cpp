class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums.back()) lo = mid + 1;
            else hi = mid;
        }

        int rot = lo;
        lo = 0, hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int real = (mid + rot) % n;

            if (nums[real] == target)
                return real;

            if (nums[real] < target) lo = mid + 1;
            else hi = mid - 1;
        }

        return -1;
    }
};


class Solution {
public:
    bool check(vector<int>& nums) {
        bool fault = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            if (nums[i] > nums[(i + 1) % n] && exchange(fault, 1))
                return 0;

        return 1;
    }
};



class Pair{
    int row;
    int col;
    Pair(int row,int col){
        this.row = row;
        this.col=col;
    }
}

class Solution {
    int cntOnes(int[][] grid) {
        // code here
        int n=grid.length;
        int m=grid[0].length;
        
        int[][] vis = new int[n][m];
        Queue<Pair>q = new LinkedList<>();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || j==m-1 || i==n-1){
                    if(grid[i][j]==1){
                        q.add(new Pair(i,j));
                        vis[i][j]=1;
                    }
                }
            }
        }
        
        int[] delrow = {-1,0,1,0};
        int[] delcol = {0,1,0,-1};
        
        while(!q.isEmpty()){
            Pair it = q.poll();
            int row = it.row;
            int col = it.col;
            
            for(int i=0;i<4;i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.add(new Pair(nrow,ncol));
                    vis[nrow][ncol]=1;
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    count++;
                }
            }
        }
        
        return count;
        
    }
};


class Solution {
    int solve(Node *root){
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int sum = root->data+left+right;
        root->data = (left+right);
        return sum;
    }
  public:
    void toSumTree(Node *root) {
        // code here
        solve(root);
    }
};


class Solution {
public:
    int n;

    int dfs(int i,vector<int>& arr,int d,vector<int>& dp) {
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans = 1;
        for(int j = i + 1;j <= min(n - 1, i + d);j++) {
            if(arr[j] >= arr[i]) {
                break;
            }
            ans = max(ans,1 + dfs(j, arr, d, dp));
        }
        for(int j = i - 1;j >= max(0, i - d);j--) {
            if(arr[j] >= arr[i]) {
                break;
            }

            ans = max(ans,1 + dfs(j, arr, d, dp));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        vector<int> dp(n, -1);
        int ans = 1;
        for(int i = 0; i < n; i++) {
            ans = max(ans,dfs(i, arr, d, dp));
        }
        return ans;
    }
};



class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]>=arr[j]) i++;
            else j--;
        }
        return arr[i];
    }
};

