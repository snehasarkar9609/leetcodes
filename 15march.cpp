#include<bits/stdc++.h>
using namespace std;
int pick;
int guess(int num){
	if(num=pick){
		return 0;
	}
	else if(num>pick) return -1;
	else return 1;
}
class Solution{
	public:
		int guessNumber(int n){
			int l=1;
			int r=n;
			while(l<=r){
				int guess_no=l+(r-l)/2;
				int val=guess(guess_no);
				if(val==0) return guess_no;
				else if(val==-1){
					r= guess_no-1;
				}
				else l= guess_no+1;
			}
			return -1;
			
		}
};
int main(){
	int n;
	cin>>n;
	cin>>pick;
	Solution obj;
	int result=obj.guessNumber(n);
	cout<<result<<endl;
	return 0;
}


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
//        int num=1;
//        int n=arr.size();
//        int i=0;
//        while(i<n && k>0){
//            if(arr[i]==num) i++;
//            else{
//                k--;
//                if(k==0) return num;
//            }
//            num++;
//        }
//        return num+k-1;

		int n=nums.size();
		int l=0,r=n-1;
		int mid=-1;
		while(l<=r){
			mid=l+(r-l)/2;
			int m=nums[mid]-(mid+1);
			if(m<k) l=mid+1;
			else r=mid-1;
		}
		return l+k;
    }
};