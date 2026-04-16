class Solution{
	public:
		string removeString(string& s){
			string r="";
			for (char ch:s){
				if(ch==' ')continue;
				r+=ch;
			}
			return r;
		}
};


