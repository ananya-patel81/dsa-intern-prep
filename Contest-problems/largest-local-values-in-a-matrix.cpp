class Solution {
private:
    bool check(int r,int c, vector<vector<int>>& matrix,vector<vector<vector<int>>>& pfx){
        int val=matrix[r][c];
        int n=matrix.size();
        int m=matrix[0].size();
        int r1=max(0,r-val);
        int r2=min(n-1,r+val);
        int c1=max(0,c-val);
        int c2=min(m-1,c+val);
        int cnt=pfx[val][r2+1][c2+1]-pfx[val][r1][c2+1]-pfx[val][r2+1][c1]+pfx[val][r1][c1];
        int dr[]={-val,-val,val,val}; //for the 4 corners 
        int dc[]={-val,val,-val,val};

        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nc>=0 && nr<n && nc<m && matrix[nr][nc]>val) cnt--;
        }

        return cnt==0;
    }

public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<vector<int>>> pfx(201,vector<vector<int>>(n+1,vector<int>(m+1,0)));
        for(int v=0;v<=200;v++){
            for(int i=0;i<n;i++){
                int res=0;
                for(int j=0;j<m;j++){
                    if(matrix[i][j]>v) res+=1;
                    pfx[v][i+1][j+1]=res+pfx[v][i][j+1];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) continue;
                if(check(i,j,matrix,pfx)) ans++;
            }
        }

        return ans;
    }
};
