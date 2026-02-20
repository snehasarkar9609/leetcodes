class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int maxi=0;
        int maxoverlap=0;
        for(vector<int>v:arr){
            maxi=max({maxi,v[0],v[1]});
            
        }
        vector<int> temp(maxi+5,0);
        for(auto it:arr){
            temp[it[0]]++;
            temp[it[1]+1]--;
        }
        for(int i=1;i<temp.size();i++){
            temp[i]=temp[i]+temp[i-1];
            maxoverlap=max(maxoverlap,temp[i]);
        }
        return maxoverlap;
    }
};


class solution{
	public:
		vector<string > readBinaryWatch(int turnedOn){
			vector<string> result;
			for(int HH=0;HH<=11;HH++){
				for(int MM=0;MM<=59;MM++){
					if(__builtin_popcount(HH)+__builtin_popcount(MM)==turnedOn){
						string hour=to_string(HH);
						string minute=(MM<10?"0"+to_string(MM):to_string(MM));
						result.push_back(hour+":"+minute);
					}
				}
			}
			return result;
		}
};