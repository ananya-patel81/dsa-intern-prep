class Solution {
private:
    vector<int> lps(string& pattern){
        int m=pattern.size();
        vector<int> lpsArr(m,0);
        int len=0;
        int i=1;
        while(i<m){
            if(pattern[len]==pattern[i]){
                len++;
                lpsArr[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lpsArr[len-1];
                }
                else{
                    lpsArr[i]=0;
                    i++;
                }
            }
        }
        return lpsArr;

    }
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string newS=s+'$';
        reverse(s.begin(),s.end());
        newS+=s;
        reverse(s.begin(),s.end());
        vector<int> lpsArr=lps(newS);
        int matched=lpsArr[newS.size()-1];
        string add= s.substr(matched);
        reverse(add.begin(),add.end());
        return add+s;
        
    }
};
