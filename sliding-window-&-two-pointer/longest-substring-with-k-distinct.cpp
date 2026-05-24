class Solution {
  
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.length();
        
        int left=0;
        int maxLen=-1;
        int right=0;
        unordered_map<char,int> mpp;
        while(right<n){
            mpp[s[right]]++;
            while(mpp.size()>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0) mpp.erase(s[left]);
                left++;
            }
            
            if (mpp.size() == k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }

        return maxLen;
        
        
        
    
    }
};
