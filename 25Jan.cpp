class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-k;i++){
        	int minans=nums[i+k-1]-nums[i];
        	ans=min(ans,minans);
		}
		return ans;
    }
};

class Solution{
	public:
		string removeDuplicate(String s){
			`stack<char>st;
			int n=s.length();
			string result="";
			for(int i=0;i<n;i++){
				if(st.empty()||st.top()!=s[i]) st.push(s[i]);
				else st.pop();
			}
			while(!st.empty()){
				result.push_back(st.top());
				st.pop();
			}
			reverse(result.begin(),result.end());
			return result;
			
		}
};

class Solution{
	public:
		bool rotateString(string s,string goal){
			int m=s.length();
			int n=goal.length();
			if(m!=n) return false;
//			for(int count=1;count<=m;count++){
//				rotate(begin(s),begin(s)+1,end(s));
//				if(s==goal) return true;
//			}
//			return false;
			if((s+s).find(goal)!=string::npos){
				return true;
			}
			return false;
		}
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans = "";

        for (int i = 0; i < s[0].length(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (i >= s[j].length() || s[j][i] != s[0][i]) {
                    return ans;
                }
            }
            ans += s[0][i];
        }
        return ans;
    }
};


