class Solution{
	public:
		bool isBinaryPalindrome(int n){
			string s="";
			while(n>0){
				s+=(n%2)+'0';
				n/=2;
			}
			int i=0,j=s.size()-1;
			while(i<j){
				if(s[i]!=s[j]) return false;
				i++;
				j--;
			}
			return true;
		}
};


class Solution{
	public:
		void rotate(vector<vector<int>>& matrix){
			int m=matrix.size();
			int n=m;
			for(int i=0;i<m;i++){
				for(int j=i;j<n;j++){
					swap(matrix[i][j],matrix[j][i]);
				}
			}
			for(int i=0;i<n;i++){
				reverse(matrix[i].begin(),matrix[i].end());
			}
		}
};



/