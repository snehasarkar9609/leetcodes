class Solution{
	public:
		bool checkBalanced(vector<int>& freq){
			int common=0;
			for(int i=0;i<26;i++){
				if(freq[i]==0) continue;
				if(common ==0) common=freq[i];
				else if(freq[i]!=common) return false;
			}
			return true;
		}
		int longestBalanced(string s){
			int n=s.length();
			int maxL=0;
			for(int i=0;i<n;i++){
				vector<int> freq(26,0);
				for(int j=i;j<n;j++){
					freq[s[j]-'a']++;
					if(checkBalanced(freq)){
						maxL=max(maxL, j-i+1);
					}
				}
			}
			return maxL;
		}
};


class Solution {
  public:
    bool check(vector<int>& arr, int k, int w, long long m){
        vector<long long> carry(arr.size(), 0);
        long long val = 0;

        for(int i = 0; i < arr.size(); i++){
            if(i != 0)
                carry[i] += carry[i-1];

            long long cur = (long long)arr[i] + carry[i];

            if(cur >= m)
                continue;
            else{
                long long d = m - cur;
                val += d;
                carry[i] += d;
                if(i + w < arr.size())
                    carry[i + w] -= d;
            }
        }
        return val <= k;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        long long ans = 0;
        long long low = *min_element(arr.begin(), arr.end());
        long long high = 1e9;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            if(check(arr, k, w, mid)){
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};


class Solution{
	public:
		int findPivot(vector<int>& nums int l, int r){
			while(l<r){
				while(l<r && nums[l]==nums[l+1])l++;
				while(l<r && nums[r]==nums[r-1]) r--;
				int mid=l+(r-l)/2;
				if(nums[mid]>nums[r])l=mid+1;
				else r=mid;
			}
			return r;
		}
		bool binarySearch(vector<int>& nums, int l, int r, int& target){
			while(l<=r){
				int mid=l+(r-l)/2;
				if(nums[mid]==target) return true;
				else if(nums[mid]<target) l=mid+1;
				else return r=mid-1;
			}
			return r;
		}
		bool search(vector<int>& nums, int target){
			int n=nums.size();
			int pivot=findPivot(nums,0,n-1);
			if(binarySearch(nums,0,pivot-1,target)) return true;
			return binarySearch(nums,pivot,n-1, target);
		}
};


class Solution{
	public:
		int guessNumber (int n){
			int l=1;
			int r=n;
			while(l<=r){
				int guess_no=l+(r-l)/2;
				int val=guess(guess_no);
				if(val==0) return guess_no;
				else if(val==-1) r=guess_no-1;
				else l=guess_no+1;
			}
			return -1;
		}
};


