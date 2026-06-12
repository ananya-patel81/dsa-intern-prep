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
public: //for first occurence index of a pattern ; TC= O(n+m);
    int strStr(string haystack, string needle) {
        vector<int> lpsArr=lps(needle);
        int i=0;
        int j=0;
        int n=haystack.size();
        int m=needle.size();
        int start=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m){
                return i-m;
            }

            else if(i<n && haystack[i]!=needle[j]){
                if(j!=0) j=lpsArr[j-1];
                else i++;
            }
        }

        return -1;
        
    }
};
