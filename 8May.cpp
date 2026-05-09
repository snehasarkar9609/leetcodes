class Solution{
	public:
		unordered_set<string> ans;
		bool isValid(string &s){
			int count=0;
			for(char ch:s){
				if(ch=='(') count++;
				else if(ch==')'){
					count--;
					if(count<0) return false;
				} 
				
			}
			return count==0;
		}
		void solve(string s, int removals){
			if(removals==0){
				if(isValid(s)) ans.insert(s);
				return ;
			}
			int n=s.size();
			for(int i=0;i<n;i++){
				if(i>0 && s[i]==s[i-1]) continue;
				if(s[i]!='(' && s[i]!=')') continue;
				string left=s.substr(0,i);
				string right=s.substr(i+1);
				solve(left+right,removals-1);
			}
			
		}
		vector<string> validParenthesis(string s){
			int open=0,close=0;
			for(char ch:s){
				if(ch=='(') open++;
				else if(ch==')'){
					if(open>0) open--;
					else close++;
				}
				
			}
			int removals=open+close;
			solve(s,removals);
			vector<string> res(ans.begin(),ans.end());
			sort(res.begin(),res.end());
			return res;
		}
};



class Solution{
	public:
		bool isPrime(int x){
			if(x<2) return false;
			for(int i=2;i*i<=x;i++){
				if(x%i==0) return false;
			}
			return true;
		}
		int minJumps(vector<int>& nums){
			int n=nums.size();
			unordered_map<int,vector<int>>mp;
			for(int i=0;i<n;i++){
				int x=nums[i];
				for(int d=2;d*d<=nums[i];d++){
					if(x%d==0){
						mp[d].push_back(i);
						while(x%d==0) x/=d;
					}
				}
				if(x>1) mp[x].push_back(i);
			}
			queue<int>q;
			vector<int> vis(n,0);
			q.push(0);
			vis[0]=1;
			int steps=0;
			while(!q.empty()){
				int sz=q.size();
				while(sz--){
					int idx=q.front();
					q.pop();
					if(idx==n-1) return steps;
					if(idx-1>=0 && !vis[idx-1]){
						vis[idx-1]=1;
						q.push(idx-1);
					}
					if(idx+1<n && !vis[idx+1]){
						vis[idx+1]=1;
						q.push(idx+1);
					}
					int val=nums[idx];
					if(isPrime(val)){
						for(int nxt:mp[val]){
							if(!vis[nxt]){
								vis[nxt]=1;
								q.push(nxt);
							}
						}
						mp.erase(val);
					}
				}
				steps++;
			}
		
		return -1;
	}
};