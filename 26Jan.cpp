class Solution{
	public:
		vector<vector<int>>minimumAbsDifference(vector<int>& arr){
			int n=arr.size();
			sort(begin(arr),end(arr));
			int minDiff=INT_MAX;
			for(int i=1;i<n;i++){
				int diff=arr[i]-arr[i-1];
				minDiff=min(minDiff,diff);
			}
			vector<vector<int>> result;
			for(int i=1;i<n;i++){
				if(diff==minDiff){
					result.push_back({arr[i-1],arr[i]});
				}
			}
			return result;
		}
};


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;

            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;

            currRow += goingDown ? 1 : -1;
        }

        string result;
        for (string row : rows)
            result += row;

        return result;
    }
};
