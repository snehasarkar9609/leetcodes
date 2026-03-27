class Solution {
public:
    vector<int> moves = {-1, 0, 1};
    vector<vector<vector<int>>> vec;
    int solve(vector<vector<int>>& grid, int row, int r1c, int r2c) {

        if (r1c < 0 || r1c >= grid[0].size() || r2c < 0 || r2c >= grid[0].size())
            return INT_MIN;

        int curr = grid[row][r1c];
        if (r1c != r2c)
            curr += grid[row][r2c];

        if (row == grid.size() - 1)
            return curr;

        if (vec[row][r1c][r2c] != -1)
            return vec[row][r1c][r2c];

        int res = INT_MIN;

        for (int i = 0; i < moves.size(); i++)
            for (int j = 0; j < moves.size(); j++)
                res = max(res, solve(grid, row + 1, r1c + moves[i], r2c + moves[j]));

        return vec[row][r1c][r2c] = res + curr;
    }
    int maxChocolate(vector<vector<int>>& grid) {
        vec = vector<vector<vector<int>>>(
            grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return solve(grid, 0, 0, grid[0].size() - 1);
    }
};


class Solution{
	public:
		bool canPartitionGrid(vector<vector<int>>& grid){
			int m=grid.size();
			int n=grid[0].size();
			for(int cut=0;cut<m-1;cut++){
				long long upper=0,lower=0;
			}
			for(int i=0;i<cut;i++){
				for(int j=0;j<n;j++){
					upper+=grid[i][j];
				}
			}
			for(int i=cut+1;i<m;i++){
				for(int j=0;j<n;j++){
					lower+=grid[i][j];
				}
			}
			if(upper==lower) return true;
		}
		for(int cut=0;cut<n-1;cut++){
			long long left=0,right=0;
			for(int j=0;j<=cut;j++){
				for(int i=0;i<m;i++){
					left+=grid[i][j];
				}
			}
			for(int j=cut+1;j<n;j++){
				for(int i=0;i<m;i++){
					right+=grid[i][j];
				}
			}
			if(left==right) return true;
		}
		return false;
	}
};


class Solution{
	public:
		bool possible(vector<int>& time, long long givenTime, int totalTrips){
			long long actualTrips=0;
			for(int &t: time){
				actualTrips+=givenTime/t;
				if(actualTrips>=totalTrips) return true;
			}
			return actualTrips>=totalTrips;
		}
		long long minimumTime(vector<int>& time, int totalTrips){
			int n=time.size();
			long long l=1;
			long long r=(long long)*min_element(time.begin(),time.end())*totalTrip;
			while(l<r){
				long long mid=l+(r-l)/2;
				if(possible(time,mid,totalTrips)){
					r=mid;
				}
				else{
					l=mid+1;
				}
			}
			return l;
		}
};


class Solution{
	public:
		string orderlyQueue(string s,int k){
			if(k>1){
				sort(begin(s),end(s));
				return s;
			}
			string result=s;
			int n=s.length();
			for(int l=1;l<=n-1;l++){
				string temp=s.substr(i)+s.substr(0,i);
				result=min(result,temp);
			}
			return result;
		}
};


class Solution{
	public:
		bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2){
			int m=word1.size();
			int n=word2.size();
			int w1i=0,i=0;
			int w2i=0,j=0;
			while(w1i<m && w2i<n){
				if(word1[w1i][i]!=word2[w2i][j]) return false;
				i++;
				j++;
				if(i==word1[w1i].length()){
					i=0;
					w1i++;
				}
				if(j==word2[w2i].length()){
					j=0;
					w2i++;
				}
				
			}
			if(w1i==word1.size() && w2i==word2.size()) return true;
			return false;
		}
};


class Solution{
	public:
		bool areSimilar(vector<vector<int>>& mat, int k){
			int m=mat.size();
			int n=mat[0].size();
			k=k%n;
			if(k==0) return true;
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					int currIdx=j;
					int finalIdx;
					if(i%2==0){
						finalIdx=(j+k)%n;
						
					}
					else finalIdx=(j-k+n)%n;
					
				}
				if(mat[i][currIdx]!=mat[i][finalIdx]) return false;
			}
			return true;
			
		}
};


bool areSimilar(vectot<vector<int>>& mat, int k){
	int m=mat.size();
	int n-mat[0].size();
	k=k%n;
	if(k==0) return true;
	for(int i=0;i<m;i++){
		vector<int>rotated=mat[i];
		if(i%2==0) rotate(rotated.rbegin(), rotated.rbegin()+k),rotated.rend();
		else rotate(rotated.begin(),rotated.begin()+k,rotated.end());
		if(rotated!=mat[i]) return false;
	}
	return true;
	
}