class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og_col=image[sr][sc];
        if(og_col==color) return image;
        int m=image.size();
        int n=image[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{sr,sc},color});
        image[sr][sc]=color;
        vector<int> drow={-1,0,+1,0};
        vector<int> dcol={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int col=q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int nrow=r+drow[d];
                int ncol=c+dcol[d];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==og_col){
                    image[nrow][ncol]=color;
                    q.push({{nrow,ncol},image[nrow][ncol]});
                }
            }

        }

        return image;
    }
};
