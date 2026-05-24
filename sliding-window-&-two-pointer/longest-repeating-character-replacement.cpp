class Solution {
public:
    int characterReplacement(string s, int k) {
        // can be converted into a longest subarray problem.
        int n=s.length();
        int left=0;
        int right=0;
        int maxFreq=0;
        int maxLen=0;
        unordered_map<char,int> mpp;
        while(right<n){
            mpp[s[right]]++;
            maxFreq=max(maxFreq,mpp[s[right]]);
            if((right-left+1)-maxFreq>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0) mpp.erase(s[left]);
                left++;
            }
            if((right-left+1)-maxFreq<=k){
                maxLen=max((right-left+1),maxLen);
            }
            right++;

        }
        return maxLen;
        
    }
};
