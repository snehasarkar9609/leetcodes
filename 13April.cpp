class Solution{
	public:
		vector<int> generateNextPalindrome(vector<int> nums, int n){
			bool all9=true;
			for(int x:num){
				if(x!=9){
					all9=false;
					break;
				}
			}
			if(all9){
				vector<int> res(n+1,0);
				res[0]=1;
				res[n]=1;
				return res;
			}
			vector<int> ans=num;
			int i=0;j=n-1;
			while(i<j){
				ans[j]=ans[i];
				i++;
				j--;

			}
			if(ans>num) return ans;
			int carry=1;
			int mid=n/2;
			if(n%2==1){
				ans[mid]+=carry;
				carry=ans[mid]/10;
				ans[mid]%=10;
				i=mid-1;
				j=mid+1;
			}
			else{
				i=mid-1;
				j=mid;
			}
			while(i>=0){
				ans[i]+=carry;
				carry=ans[i]/10;
				ans[i]%=10;
				ans[j]=ans[i];
				i--;
				j++;
			}
			return ans;
		}
};



class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n = num.size();
        vector<int> ans = num;
        for(int i = (n+1)/2, j = n-i-1 ; i < n ; i++) {
            if(num[j] > num[i]){
                while(i < n){
                    ans[i] = num[j];
                    i++;
                    j--;
                }
                return ans;
            } else if(num[j] < num[i]) break;
            ans[i] = num[j];
            j--;
        }
        
        for(int i = (n-1)/2 ; i >= 0 ; i--){
            if(num[i] != 9){ 
                ans[i]++;
                ans[n-i-1] = ans[i];
                i--;
                while(i >= 0){
                    ans[n-i-1] = ans[i];
                    i--;
                }
                return ans;
            }
            else {
                ans[i] = 0;
                ans[n-i-1] = 0;
            }
        }
        
        ans[0] = 1;
        for(int i = 1 ; i < n ; i++) ans[i] = 0;
        ans.push_back(1);
        return ans;
    }
};


class Solution{
	public:
		int getMinDistance(vector<int>nums, int target, int start){
			int result=INT_MAX;
			int n=nums.size();
			for(int i=0;i<n;i++){
				if(nums[i]==target){
					result=min(result,abs(i-start));
				}
			}
			return result;
		}
};



class Solution{
	public:
		bool isValid(vector<int>nums, int mid_max,int n){
			vector<long long> arr(begin(nums), end(nums));
			for(int i=0;i<n-1;i++){
				if(arr[i]>mid_max){
					return false;
					
				}
				long long buffer=mid_max-arr[i];
				arr[i+1]=arr[i+1]-buffer;
			}
			return arr[n-1]<=mid_max;
		}
		int minimizeArrayValue(vector<int>& nums){
			int n=nums.size();
			int maxL=0;
			int maxR=*max_element(begin(nums),end(nums));
			int result=0;
			while(maxL<=maxR){
				int mid_max=maxL+(maxR-maxL)/2;
				if(isValid(nums,mid_max,n)){
					result=mid_max;
					maxR=mid_max-1;
				}
				else{
					maxL=mid_max+1;
				}
			}
			return result;
		}
};



class Solution{
	public:
		int maxVal(int n, int index, int maxSum ){
			int ans=1;
			for(int val=1;val<=maxSum;val++){
				long long sum=val;
				int curr=val-1;
				for(int i=index-1;i>=0;i--){
					sum+=max(1,curr);
					cur--;
				}
				curr=val-1;
				for(int i=index+1;i<n;i++){
					sum+=max(1,curr);
					curr-;
					
				}
				if(sum<=maxSum){
					ans=val;
				}
				else break;
			}
			return ans;
		}
};