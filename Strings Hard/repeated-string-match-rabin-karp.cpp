class Solution {
private: 
    bool rabinKarp(string& text, string& pattern){
        using ull=unsigned long long;
        int n=text.size();
        int m =pattern.size();
        if(m>n) return false;

        ull patternHash=0;
        ull windowHash=0;
        ull BASE=131;
        ull highestBase=1;

        for(int i=0;i<m;i++){
            patternHash=patternHash*BASE + pattern[i];
            windowHash=windowHash*BASE + text[i];
            if(i<m-1) highestBase*=BASE;
        }

        for(int start=0;start<=n-m;start++){
            if(windowHash==patternHash){
                bool match=true;
                for(int j=0;j<m;j++){
                    if(pattern[j]!=text[start+j]){
                        match=false;
                        break;
                    }
                }
                if(match) return true;

            }

            if(start<n-m){
                windowHash-= (ull)(unsigned char)text[start]*highestBase;
                windowHash*=BASE;
                windowHash+= (unsigned char)text[start+m];
            }
        }

        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int count = 1;

        while (s.size() < b.size()) {
            s += a;
            count++;
        }

        if (rabinKarp(s,b)){
            return count;
        }
        s += a;

        if (rabinKarp(s,b)){
            return count + 1;
        }
        return -1;
    }
};
