class Solution {
// private:
//     bool f(int i, int j,string& s, string& p, vector<vector<int>>& dp){
//         if(i==0 && j==0) return true;
//         if(i==0 && j>0) return false;
//         if(i>0 && j==0){
//             for(int ii=1;ii<=i;ii++){
//                 if(p[ii-1]!='*') return false;
//             }
//             return true;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(p[i-1]==s[j-1] || p[i-1]=='?'){
//             return dp[i][j]=f(i-1,j-1,s,p,dp);
//         }
//         if(p[i-1]=='*'){
//             return dp[i][j]= (f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp));
//         }
//         return dp[i][j]=false;
//     }
public:
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<bool> prev(m+1,false);
        prev[0]=true;
        // for(int i=1;i<=n;i++){
        //     int flag=true;
        //     for(int ii=1;ii<=i;ii++){
        //         if(p[ii-1]!='*') {
        //             flag= false;
        //             break;
        //         }
        //     }
        //     dp[i][0]=flag;

        // }
        vector<bool> curr(m+1,false);
        for(int i=1;i<=n;i++){
            int flag=true;
            for(int ii=1;ii<=i;ii++){
                if(p[ii-1]!='*') {
                    flag= false;
                    break;
                }
            }
            curr[0]=flag;
            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?'){
                    curr[j]=prev[j-1];
                }
                else if(p[i-1]=='*'){
                    curr[j]= (prev[j] || curr[j-1]);
                }
                else{
                    curr[j]=false;

                }
            }
            prev=curr;
        }
        return prev[m];

        
    }
};
