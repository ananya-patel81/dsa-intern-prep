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
    string longestPrefix(string s) {
        vector<int> lpsArr= lps(s);
        int maxi=0;
        
        maxi=lpsArr[s.size()-1];

        return s.substr(0,maxi);
        
    }
};
