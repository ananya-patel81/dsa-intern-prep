class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_freq;
        for(char ch : t){
            t_freq[ch]++;
        }
        unordered_map<char,int> sub_freq;
        int l = 0;
        int have = 0;
        int need = t_freq.size();
        int resLen = INT_MAX;
        pair<int,int> res={-1,-1};
        for(int r=0;r<s.length();r++){
            char c = s[r];
            sub_freq[c]++;
            if(t_freq.count(c) && sub_freq[c]==t_freq[c]){
                have++;
            }
            while(have==need){
                if(resLen>(r-l+1)){
                    resLen=(r-l+1);
                    res ={l,r};
                }
                sub_freq[s[l]]--;
                if(t_freq.count(s[l]) && sub_freq[s[l]]<t_freq[s[l]]){
                    have--;
                }
                l++;
            }
            
            
        }

        return (resLen == INT_MAX) ? "" : s.substr(res.first,resLen);
        
    }
};
