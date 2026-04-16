class Solution{
	public:
		int myAtoi(string s){
			int i=0, n=s.length();
			while(i<n && s[i]==' ')i++;
			int sign=1;
			if(i<n &&(s[i]=='+'||s[i]=='-')){
				if(s[i]=='-')sign =-1;
				i++;
			}
			long long num=0;
			while(i<n && isdigit(s[i])){
				num=num*10+(s[i]-'0');
				if(sign*num>=INT_MAX)return INT_MAX;
				if(sign*num<=INT_MAX) return INT_MIN;
				i++;
			}
			return sign*num;
		}
};


class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        while(i < n && s[i] == ' ') i++;
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }
        long long num = 0;
        while(i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if(sign * num >= INT_MAX) return INT_MAX;
            if(sign * num <= INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return sign * num;
    }
};


class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            vector<int>& v = mp[nums[q]];

            // only one occurrence
            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();
            int res = INT_MAX;

            // left neighbor
            int left = v[(pos - 1 + v.size()) % v.size()];
            int d1 = abs(q - left);
            res = min(res, min(d1, n - d1));

            // right neighbor
            int right = v[(pos + 1) % v.size()];
            int d2 = abs(q - right);
            res = min(res, min(d2, n - d2));

            ans.push_back(res);
        }

        return ans;
    }
};


