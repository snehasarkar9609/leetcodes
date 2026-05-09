class Solution {
  public:
  
    long long determinant(vector<vector<long double>>& mat, int n){
        
        long double det = 1;
        
        for(int i = 0; i < n; i++){
            
            int pivot = i;
            
            for(int j = i; j < n; j++){
                
                if(fabsl(mat[j][i]) > fabsl(mat[pivot][i])){
                    pivot = j;
                }
            }
            
            if(fabsl(mat[pivot][i]) < 1e-9){
                return 0;
            }
            
            if(i != pivot){
                swap(mat[i], mat[pivot]);
                det *= -1;
            }
            
            det *= mat[i][i];
            
            for(int j = i + 1; j < n; j++){
                
                long double factor = mat[j][i] / mat[i][i];
                
                for(int k = i; k < n; k++){
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }
        
        return round(det);
    }
  
  
    int countSpanTree(int n, vector<vector<int>>& edges) {
        
        if(n == 1){
            return 1;
        }
        
        vector<vector<long double>> lap(n, vector<long double>(n, 0));
        
        for(auto &e : edges){
            
            int u = e[0];
            int v = e[1];
            
            lap[u][u]++;
            lap[v][v]++;
            
            lap[u][v]--;
            lap[v][u]--;
        }
        
        vector<vector<long double>> minor(n - 1, vector<long double>(n - 1));
        
        for(int i = 1; i < n; i++){
            
            for(int j = 1; j < n; j++){
                
                minor[i - 1][j - 1] = lap[i][j];
            }
        }
        
        return determinant(minor, n - 1);
    }
};


class Solution{
	public:
		vector<int> plusOne(vector<int>& digits){
			int n=digits.size();
			int i=n-1;
			while(i>=0){
				if(digits[i]<=8){
					digits[i]+=1;
					return digits;
				}
				else if(digits[i]==9){
					digits[i]=0;
					i--;
				}
			}
			digits.insert(begin(digits),1);
			return digits;
		}
};


class Solution{
	public:
		vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k){
			int m=grid.size();
			int n=grid[0].size();
			int layers=min(m,n)/2;
			for(int layer=0;layer<layers;layer++){
				vector<int> nums;
				int top=layer;
				int bottom=m-layer-1;
				int left=layer;
				int right=n-layer-1;
				for(int j=left;j<=right;j++){
					nums.push_back(grid[top][j]);
				}
				for(int i=top+1;i<=bottom-1;i++){
					nums.push_back(grid[i][right]);
				}
				for(int j=right;j>=left;j--){
					nums.push_back(grid[bottom][j]);
				}
				for(int i=bottom-1;i>=top+1;i--){
					nums.push_back(grid[i][left]);
				}
				int len=nums.size();
				int normalized_k=k%len;
				rotate(begin(nums),begin(nums)+normalized_k,end(nums));
				int idx=0;
				for(int j=left;j<=right;j++){
					grid[top][j]=nums[idx++];
					
				}
				for(int i=top+1;i<=bottom-1;i++){
					grid[i][right]=nums[idx++];
					
				}
				for(int j=right;j>=left;j--){
					grid[bottom][j]=nums[idx++];
				}
				for(int i=bottom -1;i>=top+1;i--){
					grid[i][left]=nums[idx++];
				}
				
			}
			return grid;
		}
};