class Solution{
	public:
		int countBuildings(vector<int>& arr){
			int count=0;
			int maxheight=0;
			int n=arr.size();
			for(int i=0;i<n;i++){
				if(arr[i]>=maxheight){
					count++;
					maxheight=arr[i];
				}
			}
			return count;
		}
};



class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blanks = 0;

        for (char c : moves) {
            if (c == 'L') left++;
            else if (c == 'R') right++;
            else blanks++;
        }

        return abs(left - right) + blanks;
    }
};