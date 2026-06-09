class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n=seats.size();
        for(int i=0;i<n;i++){
            if(seats[i]==0 &&(i==seats.size()-1||seats[i+1]!=1)&& (i==0||seats[i-1]!=1)){
                k--;
                if(k==0) return true;
                seats[i]=1;
            }
        }
        return k==0;
    }
};


class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n = seats.size();

        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                int left = (i == 0) ? 0 : seats[i - 1];
                int right = (i == n - 1) ? 0 : seats[i + 1];

                if (left == 0 && right == 0) {
                    seats[i] = 1;
                    k--;

                    if (k == 0)
                        return true;
                }
            }
        }

        return k <= 0;
    }
};



class Solution {
  public:
    virtual int binarySearchable(int Arr[], int n) {
      vector<int> maxv(n), minv(n);
      
      maxv[0]=INT_MIN;
      for(int i=1; i<n; i++){ maxv[i] = max(maxv[i-1], Arr[i-1]); }      
      
      minv[n-1]=INT_MAX;
      for(int i=n-2; i>=0; i--){ minv[i] = min(minv[i+1], Arr[i+1]); }
      
      
      int ans=0;
      for(int i=0; i<n; i++){
        if(maxv[i]<=Arr[i] && Arr[i]<=minv[i]) ans++;
      }
      
      return ans;
    }
};