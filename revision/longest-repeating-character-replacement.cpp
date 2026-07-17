class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int max_len = 0;
        int n = s.size();
        int l =0;
        int maxf=0;
        for(int r =0 ;r<n;r++){
            mpp[s[r]]++;
            maxf= max(maxf, mpp[s[r]]);

            while((r-l+1)-maxf > k){
                mpp[s[l]]--;
                l++;

            }

            max_len=max(max_len,(r-l+1));
        }
        return max_len;
    }
};
