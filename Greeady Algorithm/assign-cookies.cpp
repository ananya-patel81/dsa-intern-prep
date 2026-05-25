class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //check if you can satisfy the kids with the most amount of want. 
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;
        int r=0;
        int n=g.size(), m=s.size();
        while(l<m && r<n){
            if(g[r]<=s[l]){
                r=r+1;
            }
            l=l+1;

        }
        return r;
    }
};
