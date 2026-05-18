class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int> res;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(res.size()==0) res.push_back(arr[i]);
            else{
                if((res.back()>0 && arr[i]<0) or (res.back()<0 && arr[i]>0)
                or(arr[i]==0 and res.back()<0)or(res.back()==0 and arr[i]<0)) res.pop_back();
                else res.push_back(arr[i]);
            }
        }
        return res;
    }
};


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i < 0 || i >= n || visited[i])
                continue;

            if (arr[i] == 0)
                return true;

            visited[i] = true;

            q.push(i + arr[i]);
            q.push(i - arr[i]);
        }

        return false;
    }
};