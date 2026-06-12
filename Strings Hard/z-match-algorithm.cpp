class Solution {
  private:
    vector<int> zMatch(string& txt){
        vector<int> z(txt.size(),0);
        int l=0,r=0;
        for(int i=1;i<txt.size();i++){
            if(i<r){
                z[i]=z[i-l];
                if(i+z[i]>r){
                    z[i]=r-i;
                }
            }
            
            while(i+z[i]<txt.size() && txt[z[i]]==txt[i+z[i]]){
                z[i]++;
            }
            
            if(i+z[i]>r){
                l=i;
                r=i+z[i];
            }
        }
        
        return z;
    }
  public:
    vector<int> search(string &pat, string &txt) {
        string newS= pat + '$' + txt;
        int matchLen=pat.size();
        vector<int> zArr=zMatch(newS);
        vector<int> ans;
        for(int i=matchLen+1;i<newS.size();i++){
            if(zArr[i]==matchLen){
                ans.push_back(i-(matchLen+1));
            }
        }
        return ans;
        
    }
};
