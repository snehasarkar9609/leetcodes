class Solution {
    vector<vector<int>> dp;

    int solve(int idx, int prevSum, string &s) {
        int n = s.size();

        if (idx == n)
            return 1;

        if (dp[idx][prevSum] != -1)
            return dp[idx][prevSum];

        int ans = 0;
        int currSum = 0;

        for (int end = idx; end < n; end++) {

            currSum += s[end] - '0';

            if (currSum >= prevSum) {
                ans += solve(end + 1, currSum, s);
            }
        }

        return dp[idx][prevSum] = ans;
    }

public:
    int validGroups(string &s) {
        int n = s.size();

        dp.assign(n, vector<int>(901, -1));

        return solve(0, 0, s);
    }
};



class Solution {
public:
    int minElement(vector<int>& nums) {
        int res=36;
        for(auto& n:nums){
            res=min(res,n-9*((n/10)+(n/100)+(n/1000)+(n/10000)));
        }
        return res;
    }
};