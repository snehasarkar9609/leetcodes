class Solution {
  public:
    
    int solve(int i, bool buy, vector<int>& arr, int& k, vector<vector<int>>& dp) {
        
        if (i >= arr.size()) {
            return 0;
        }
        
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        int profit = solve(i+1, buy, arr, k, dp);
        
        if (buy) {
            int ans = -arr[i] - k + solve(i+1, false, arr, k, dp);
            profit = max(profit, ans);
        } else {
            int ans = arr[i] + solve(i+1, true, arr, k, dp);
            profit = max(profit, ans);
        }
        
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, true, arr, k, dp);
    }
};


class Solution {
public:
    string generateString(string s, string t) {
        int n=s.size(),m=t.size();
        string ans(n+m-1,'?');
        for(int i=0;i<n;i++){
            if(s[i]!='T') continue;
            for(int j=0;j<m;j++){
                char v=ans[i+j];
                if(v!='?' && v!=t[j]){
                    return "";
                }
                ans[i+j]=t[j];
            }
        }
        string old_ans=ans;
        for(char& c:ans){
            if(c=='?')c='a';
        }
        for(int i=0;i<n;i++){
            if(s[i]!='F') continue;
            if(string(ans.begin()+i, ans.begin()+i+m)!=t) continue;
            bool ok=false;
            for(int j=i+m-1;j>=i;j--){
                if(old_ans[j]=='?'){
                    ans[j]='b';
                    ok=true;
                    break;
                }
            }
            if(!ok) return "";
        }
        return ans;
    }
};


class Solution{
	public:
		bool canEatAll(vector<int>& piles,int mis,int h){
			int actualHours=0;
			for(int&x:piles){
				actualHours+=x/mid;
				if(x%mid!=0){
					actualHours++;
				}
			}
			return actualHours<=h;
		}
		int minEatingSpeed(vector<int>& piles, int h){
			int n=piles.size();
			int l=1;
			int r=*max_element(piles.begin(),piles.end());
			while(l<r){
				int mid=l+(r-l)/2;
				if(canEatAll(piles,mid,h)){
					r=mid;
				}
				else l=mid+1;
			}
			return l;
		}
};


class Solution{
	public:
		int solve(vector<int>& nums, int l, int r,int target){
			if(l>r) return -1;
			int mid=l+(r-l)/2;
			if(nums[mid]==target) return mid;
			else if(nums[mid]<target) return solve(nums,mid+1,r,target);
			else return solve(nums,l,mid-1,target);
			
		}
		int search(vector<int>& nums, int target){
			int n=nums.size();
			return solve(nums,0,n-1,target);
		}
};


class Solution{
	public:
		string makeGood(string s){
			string result="";
			for(char &ch:s){
				if(!result.empty() && result.back()+32==ch ||result.back()-32==ch){
					result.pop_back();
				}
				else result.push_back(ch);
			}
			return result;
		}
};



class Solution{
	public:
		bool (isVowel(char& ch)){
			return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
		}
		bool halvesAreAlike(string s){
			int n=s.lenght();
			int mid=n/2;
			int i=0,j=mid;
			int countl=0,countr=0;
			while(i<n/2 && j<n){
				if(isVowel(s[i]))count++;
				if(isVowel[s[j]])count++;
				i++;
				j++;
			}
			return countl==countr;
		}
};