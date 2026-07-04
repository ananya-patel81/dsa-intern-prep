class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        set<string> words(wordDict.begin(),wordDict.end());
        int maxLen=0;
        for(string word : wordDict){
            maxLen=max(maxLen, (int)word.length());
        }
        vector<bool> dp(s.size()+1);
        dp[0]=true;
        for(int len=1;len<=s.size();len++){
            for(int j=len-1;j>=0;j--){
                int cnt= len-j; //len-(len-1)= 1 for example, meaning length 1 string processed;
                if(cnt>maxLen) break;
                if(dp[j]){ //kyuinki isse pehle ka agar true hai toh hi abhi ka dictionary mein hone se pura true hoga, warna agar abhi tak ka processed word hota bhi par usse pehle ka part ka dp false hota toh bhi hum isko false hi declare karte; 
                    string temp=s.substr(j,cnt);
                    if(words.find(temp)!=words.end()){
                        dp[len]=true; 
                        break;
                    }

                }
            }
            
        }
        return dp[s.size()];
    }
};
