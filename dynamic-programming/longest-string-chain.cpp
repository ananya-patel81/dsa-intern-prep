class Solution {
    static bool comp(string& s1, string& s2){
        return s1.size()<s2.size();
    }
private:
    bool compare(string& s1, string& s2){
        if(s1.size()!=s2.size()+1) return false;
        int first=0;
        int second=0;
        while(first< s1.size()){
            if(s1[first]==s2[second] && second<s2.size()){
                first++;
                second++;
            }
            else{
                first++;
            }
        }

        if(first==s1.size() && second==s2.size()) return true;
        return false;
    }
   
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxi=1; //to keep track of max length of chain found so far;
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compare(words[i],words[prev]) && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                }
                

                
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }

        return maxi;
        
    }
};
