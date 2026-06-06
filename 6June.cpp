class Solution {
  public:
    int sol(int n,int m,int i,int j){
        int total=n*m;
        if(i+2<=n && j+1 <=m){
            total--;
        }
        if(i+2<=n && j-1 >=1){
            total--;
        }
        if(i-2>=1 && j+1 <=m){
            total--;
        }
        if(i-2>=1 && j-1 >=1){
            total--;
        }
        if(i-1>=1 && j+2 <=m){
            total--;
        }
        if(i+1<=n && j+2 <=m){
            total--;
        }
        if(i-1>=1 && j-2 >= 1){
            total--;
        }
        if(i+1<=n && j-2 >= 1){
            total--;
        }
        
        
        return total-1;
    }
    int numOfWays(int n, int m) {
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=sol(n,m,i,j);
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int leftSum=0;
        for(int i=0;i<n;i++){
            ans[i]=leftSum;
            leftSum+=nums[i];
        }
        int rightSum=0;
        for(int i=n-1;i>=0;i--){
            ans[i]=abs(ans[i]-rightSum);
            rightSum+=nums[i];
        }
        return ans;
            
        
    }
};