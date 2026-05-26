class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n= arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0;
        int j=0;
        int cnt=0;
        int maxCnt=INT_MIN; // for cnt of intersections.
        while(i<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }
            else if(arr[i]>dep[j]){
                cnt--;
                j++;
            }
            
            maxCnt=max(maxCnt,cnt);
            
        }
        
        return maxCnt;
    }
};
