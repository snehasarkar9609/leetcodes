class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int>mp;
        mp[0]=-1;
        int prefixsum=0,maxlen=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
        	prefixsum+=(arr[i]>k)?1: -1;
        	if(prefixsum>0) maxlen=i+1;
        	if(mp.count(prefixsum-1)){
        		maxlen=max(maxlen,i-mp[prefixsum-1]);
			}
			if(!mp.count(prefixsum)) mp[prefixsum]=i;
		}
		return maxlen;
        
    }
};


class Solution{
	public:
		int countOneBits(int num){
			int count=0;
			while(num!=0){
				count+=num&1;
				num>>=1;
			}
			return count;
		}
		vector<int>sortByBits(vector<int>& arr){
			auto lambda=[&](int &a, int &b){
				int count_a=countOneBits(a);
				int count_b=countOneBits(b);
				if(count_a==count_b)return a<b;
				return count_a<count_b;
			};
			sort(begin(arr),end(arr),lambda);
			return arr;
		}
		vector<int>sortByBits(vector<int>& arr){
			auto lambda=[&](int &a, int &b){
				int count_a=__builtin_popcount(a);
				int count_b=__builtin_popcount(b);
				if(count_a==count_b)return a<b;
				return count_a<count_b;
			};
			sort(begin(arr),end(arr),lambda);
			return arr;
		}
};


