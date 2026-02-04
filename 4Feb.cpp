class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int maxtime = 0;
        
        for(int i=0;i<left.size();i++){
            maxtime = max(maxtime,left[i]);
        }
        
        for(int i=0;i<right.size();i++){
            maxtime = max(maxtime,n-right[i]);
        }
        
        return maxtime;
    }
};


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            bool isEven;
            if((right-mid)%2==0) isEven=true;
            else isEven=false;
            if(nums[mid]==nums[mid+1]){
                if(isEven) left=mid+2;
                else right=mid-1;
            }
            else{
                if(isEven )right=mid;
                else left=mid+1;
            }
        }
        return nums[right];
    }
};


class Solution {
public:
    vector<tuple<int, int, long long> > decompose(vector<int>& nums){
        int n = (int)nums.size();
        vector<tuple<int, int, long long> > subarrays;

        int l = 0;
        long long sum = nums[0];
        
        for(int i = 1; i < n; i ++){
            // If we fail strict decreasing at boundary i-1 -> i, end the current subarray.
            if(nums[i - 1] <= nums[i]){
                subarrays.push_back({l, i - 1, sum});
                l = i;
                sum = 0;
            }
            sum += nums[i];
        }
        //last subarray
        subarrays.push_back({l, n - 1, sum});
        return subarrays;
    }
    long long maxSumTrionic(vector<int>& nums){
        int n = (int)nums.size();
        long long maxEndingAt[n];
        for(int i = 0; i < n; i ++){
            maxEndingAt[i] = nums[i];
            if(i > 0 && nums[i - 1] < nums[i]){
                if(maxEndingAt[i - 1] > 0){
                    maxEndingAt[i] += maxEndingAt[i - 1];
                }
            }
        }
        long long maxStartingAt[n];
        for(int i = n - 1; i >= 0; i --){
            maxStartingAt[i] = nums[i];
            if(i < n - 1 && nums[i] < nums[i + 1]){
                if(maxStartingAt[i + 1] > 0){
                    maxStartingAt[i] += maxStartingAt[i + 1];
                }
            }
        }
        vector<tuple<int, int, long long> > PQS = decompose(nums);
        long long ans = LLONG_MIN;
        for(auto [p, q, sum] : PQS){
            
            if(p > 0 && nums[p-1] < nums[p] &&
               q < n - 1 && nums[q] < nums[q + 1] &&
               p < q){
                ans = max(ans, maxEndingAt[p-1] + sum + maxStartingAt[q+1]);
            }
        }
        return ans;
    }
};