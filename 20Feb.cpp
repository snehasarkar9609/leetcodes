class Solultion{
	public:
		int countBinarySubstrings(string s){
			int result=0;
			int prevCount=0;
			int currCount=1;
			int n=s.length();
			for(int i=1;i<n;i++){
				if(s[i]==s[i-1]) currCount++;
				else{
					result+=min(prevCount,currCount);
					prevCount=currCount;
					currCount=1;
				}
			}
			return result+min(prevCount,currCount);
		}
};


class Cmp{
  public:
    bool operator()(string a, string b){
      if((a+b)<=(b+a)) return true;
      return false;
    }
};

class Solution {
  public:
    virtual string findLargest(vector<int> &arr) {
      priority_queue<string, vector<string>, Cmp> pq;
      for(int x: arr){
        pq.push(to_string(x));  
      }
      
      string ans="";
      while(!pq.empty()){
        if(ans!="" || pq.top() != "0")
          ans+=(pq.top());
        pq.pop();  
      }
      
      return ans==""? "0": ans;
    }
};


class Solution{
	public:
		string solve(string s){
			vector<string> specials;
			int start=0;
			int sum=0;
			int n=s.length();
			for(int i=0;i<n;i++){
				sum+=s[i]=='1'?1:-1;
				if(sum==0){
					string inner=s.substr(Start+!,i-start-1);
					specials.push_back("1"+solve(inner)+"0");
					start=i+1;
				}
			}
			sort(begin(special),end(special), greter<string>());
			string result;
			for(string &str:special){
				result+=str;
			}
			return result;
			
		}
		string makeLargestSpecial(string s){
			return solve(s);
		}
};



class Solution{
	public:
		static vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
		static vector<string> sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		string intToRoman(int num){
			string result="";
			for(int i=0;i<13;i++){
				if(num==0) break;
				int times=num/val[i];
				while(times--)result+=sym[i];
				num=numVal[i];
			}
			return result;
			
		}
};


class Solution{
	public:
		bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2){
//			int n=word1.lenght();
//			int m=word2.length();
//			string result1="";
//			string result2="";
//			for(int i=0;i<n;i++){
//				result1+=word1[i];
//			}
//			for(int i=0;i<m;i++){
//				result2+=word2[i];
//			}
//			if(result1==result2) return true;
//			return false;

			int m=word1.size();
			int n=word2.size();
			int w1i=0,int i=0;
			int w2i=0,int j=0;
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
			if(w1i==word1.size()&& w2i==word2.size()){
				return true;
			}
			return false;
			
		}
};