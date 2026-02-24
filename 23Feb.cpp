class Solution{
	public:
		bool hasAllCodes(String s, int k){
			unordered_set<string>st;
			int n=s.length();
			int codes=1<<k;
			for(int i=k;i<=n;i++){
				string sub=s.substr(i-k,k);
				if(!st.count(sub)){
					st.insert(Sub);
					codes--;
				}
				if(codes==0) return true;
			}
			return false;
		}
	};
	
	
class Solution{
	public:
		int binaryGap(int n){
//			int curr=0;
//			int prev=-1;
//			int result=0;
//			while(n>0){
//				if((n&1)>0){
//					result=(prev!=-1)? max(result,curr-prev):result;
//					prev=curr;
//				}
//				curr++;
//				n>>=1;
//			}
//			return result;
			
			
			int prev=-1;
			int result=0;
			for(int curr=0,curr<32,curr++){
				if(((n>>curr)&1)>0){
					result=(prev!=-1)?max(result,curr-prev):result;
					prev=curr;
				}
			}
			return result;
		}
};

class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        for(int i = 0;i<n;i++){
            a1[i] = a1[i]-a2[i];
        }
        map<int,int> mp;
        int sum = 0, len = 0;
        for(int i = 0;i<n;i++){
            sum+=a1[i];
            if(sum == 0){
                len = max(len, i+1);
            }
            
            auto it = mp.find(sum);
            if(it != mp.end()){
                len = max(len, i-it->second);
            }
            else{
                mp[sum] = i;
            }
        }
        return len;
    }
};