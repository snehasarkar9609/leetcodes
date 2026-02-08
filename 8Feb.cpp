class Solution{
	public:
		int minRemoval(vector<int>& nums, int k){
			int n=nums.size();
			sort(begin(nums),end(nums));
			int l=1;
			int maxEl=nums[0];
			int minEl=nums[0];
			int i=0;
			int j=0;
			while(j<n){
				minEl=nums[i];
				maxEl=nums[j];
				while(i<j && maxEl>k*minEl){
					i++;
					minEl=nums[i];
				}
				l=max(l,j-i+1);
				j++;
				
			}
			return n-l;
		}
};

class Solution{
	public:
		bool isBalanced(TreeNode* root){
			return dfsHeight(root)!-=1;
			
		}
		int dfsHeight(TreeNode* root){
			if(root==NULL) return 0;
			int leftHeight=dfsHeight(root->left);
			if(leftHeight==-1) return -1;
			int rightHeight=dfsHeight(root->right);
			if(rightHeight==-1) return -1;
			if(abs(leftHeight-rightHeight)>1) return -1;
			return max(leftHeight, rightHeight)+1;
		}
};


class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ma = arr[0];
        int mi = ma;
        int ans = ma;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]<0)
                swap(ma,mi);
            
            ma = max(arr[i],arr[i]*ma);
            mi = min(arr[i],arr[i]*mi);
            ans = max(ans,ma);
        }
        return ans;
    }
};