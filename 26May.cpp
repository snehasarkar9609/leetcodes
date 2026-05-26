class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<26>a=0,A=0;
        for(char c:word){
            if(c>='a')a[c-'a']=1;
            else A[c-'A']=1;
        }
        a=a&A;
        return a.count();
    }
};


class Solution{
	public:
		int minToggle(vector<int>& arr){
			int tot=accumulate(arr.begin(),arr.end(),0);
			int cnt=0;
			int toggles=INT_MAX;
			for(int i=0;i<arr.size();i++){
				cnt+=arr[i];
				toggles=min(toggles,cnt+((int(arr.size())-i-1)-(tot-cnt)));
			}
			toggles=min(toggles,min(cnt,int(arr.size())-cnt));
			return toggles;
		}
};


