class Solution{
	public:
		int longestBalanced(vector<int>& nums){
			int n=nums.size();
			int maxLen=0;
			for(int i=0;i<n;i++){
				unordered_set<int> even;
				unordered_set<int> odd;
				for(int j=0;j<n;j++){
					if(nums[j]%2==0){
						even.insert(nums[j]);
					}
					else{
						odd.insert(nums[j]);
					}
					if(even.size()==odd.size()){
						maxLen=max(maxLen,j-i+1);
					}
				}
			}
			return maxLen;
		}
};


class Solution {
  public:
    bool good(vector<int>& arr, int mid, int k){
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=ceil((double)arr[i]/mid);
            
        }
        return k>=ans;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int i=1;
        int j=*max_element(arr.begin(),arr.end());
        int ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(good(arr,mid,k)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};


class Solution{
	public:
		int findKRotation(int arr[], int n){
//			int result=-1;
//			int l=0;r=n-1;
//			while(l<r){
//				int mid=i+(r-l)/2;
//				if(arr[mid]<arr[r]){
//					r=mid;
//				}
//				else{
//					l=mid+1;
//				}
//			}
//			return r;
			
			int minVal=INT_MAX;
			int minIndex=0;
			for(int i=0;i<n;i++){
				if(min(arr[i],minVal==arr[i]){
					minVal=arr[i];
					minIndex=i;
				}
				
			}
			return minIndex;
		}
};


class Solution{
	public:
		int findPivot(vector<int>& nums, int n){
			int l=0,r=n-1;
			while(l<r){
				int mid=l+(r-l)/2;
				if(nums[mid]>nums[r])l=mid+1;
				else r=mid;
			}
			return r;
		}
		int binarySearch(int l, int r, vector<int>& nums, int target){
			int idx=-1;
			while(l<=r){
				if(nums[mid]==target) {
					idx=mid;
					break;
				}
				else if(nums[mid]<target){
					l=mid-1;
				}
				else r=mid-1;
			}
			return idx;
		}
		int search(vector<int>& nums, int target){
			int n=nums.size();
			int pivot_index=findPivor(nums);
			int idx=binarySearch(0,pivot_index-1,nums,target);
			if(idx!=-1) return idx;
			idx=binarySearch(pivot_index,n-1,nums, target);
			return idx;
			
		}
};