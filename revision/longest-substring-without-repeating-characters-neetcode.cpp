class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int max_len = 0;
        int l = 0;
        for(int r = 0; r<s.length();r++){
            while(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            max_len = max(max_len, r-l+1);
        }
        return max_len;
    }
};
