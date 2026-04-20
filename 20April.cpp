class Solution{
	public:
		int maxDistance(vector<int>& colors){
//			int n=colors.size();
//			int result=0;
//			for(int i=0;i<n;i++){
//				for(int j=n-1;j<n;j++){
//					if(colors[i]!=colors[j]){
//						result=max(result,abs(j-i));
//						
//				}
//			}
//			return result;

//			int n=colors.size();
//			int result=0,i=0;
//			while(colors[i]==colors[n-1])i++;
//			result=max(result,abs(i-(n-1)));
//			i=n-1;
//			while(colors[0]==colors[i])i--;
//			result=max(result,i);
//			return result;

			int n=colors.size();
			int result=0;
			for(int i=0;i<n;i++){
				if(colors[i]!=colors[0]){
					result=max(result,i);
				}
				is(colors[i]!=colors[n-1]){
					result=max(result,abs(i-(n-1)));
				}
			}
		}
};


class Solution {
public:
    long long int countDerangements(int n) {
        if(n == 1) return 0;
        if(n == 2) return 1;
        
        vector<long long> dp(n + 1);
        dp[1] = 0;
        dp[2] = 1;
        
        for(int i = 3; i <= n; i++){
            dp[i] = (i - 1) * (dp[i-1] + dp[i-2]);
        }
        
        return dp[n];
    }
};


