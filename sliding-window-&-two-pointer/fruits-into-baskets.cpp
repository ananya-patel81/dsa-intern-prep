class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int k=2;
        int l=0;
        int r=0;
        int maxlen=0;
        unordered_map<int,int> mpp;
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
            int len=r-l+1;
            if(mpp.size()<=k) maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
        
    }
};
