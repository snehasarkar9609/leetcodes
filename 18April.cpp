class Solution{
	public:
		int maxOnes(vector<int>& arr){
			int c1=0,curr=0,m=0;
			int n=arr.size();
			for(int i=0;i<n;i++){
				if(arr[i]==1) c1++;
			}
			for(int i:arr){
				int v=(i==0)?1:-1;
				curr=max(v,curr+v);
				m=max(m,curr);
			}
			return c1+m;
		}
};


class Solution{
	public:
//		int getReverse(int n){
//			int result=0;
//			while(n){
//				int lastDigit=n%10;
//				result=(result*10)+lastDigit;
//				n/=10;
//			}
//			return result;
//		}
//		int mirrorDistance(int n){
//			return abs(n-getReverse(n));
//		}
		int mirrorDistance(int n){
			string s=to_string(n);
			reverse(begin(s),end(s));
			int reverseInteger=stoi(s);
			return (abs(n-reverseInteger));
		}
};



