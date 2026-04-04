class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        const int size=1<<n;
        vector<string> result(size,string(n,'0'));
        for(int i=1;i<size;i++){
            int gray=i^(i>>1);
            string& s=result[i];
            for(int g=gray,j=n-1;g;g>>=1,j-- ){
                if(g&1) s[j]='1';
            }
        }
        return result;
    }
};


class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 1)
            return encodedText;

        int cols = n / rows;
        string res;
        res.reserve(n);

        for (int c = 0; c < cols; ++c) {
            int r = 0, j = c;
            while (r < rows && j < cols) {
                res += encodedText[r * cols + j];
                ++r;
                ++j;
            }
        }

        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};



