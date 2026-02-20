class Solution{
	public:
		string addBinary(string a, string b){
			int m=a.length()-1;
			int n=b.length()-1;
			string result="";
			int sum=0;
			int carry=0;
			while(m>=0 ||n>=0){
				sum=carry;
				if(m>=0){
					sum+=a[m]-'0';
					m--;
				}
				if(n>=0){
					sum+=b[n]-'0';
					n--;
				}
				result.push_back((sum%2==0)?'0':'1');
				carry=(sum>1)?1:0;
			}
			if(carry==1) result.push_back('1');
			reverse(begin(result), end(result));
			return result;
		}
};


class Solution{
	public:
		int reverseBits(int n){
			if (n==0) return 0;
			int result=0;
			for(int i=1;i<32;i++){
				result<<=1;
				result=(result|(n&1));
				n>>=1;
			}
			return result;
		}
};


class Solution{
	public:
		string countAndSay(int n){
			if(n==1) return "1";
			string say=countAndSay(n-1);
			string result="";
			for(int i=0;i<say.length();i++){
				char ch=say[i];
				int count=1;
				while(i<say.length()-1 && say[i]==say[i+1]){
					count++;
					i++;
				}
				result+=to_string(count)+string(1,ch);
				
			}
			return result;
		}
};



