class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mpp; //<presum,index>
        int presum=0;
        int longest=0;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            presum+=arr[i];
            int remain=presum-k;
            if(mpp.find(remain)!=mpp.end()) longest=max(longest,(i-mpp[remain]));
            if (mpp.find(presum) == mpp.end()) { //if you overwrite the previous occurences, 
            // you forget the earliest possible starting point, which accidentally shortens
            // the maximum potential subarray length;
                mpp[presum] = i;
            }
        }
        return longest;
        
    }
};
