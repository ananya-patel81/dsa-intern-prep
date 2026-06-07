string findLCS(int n, int m,string &text1, string &text2){
	
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }	

	int start=dp[n][m];
	int i=n; 
	int j=m;
	string str="";
	for(int k=0;k<start;k++) str+='$';
	int index=start-1;
	while(i>0 && j>0){
		if(text1[i-1]==text2[j-1]){
			str[index]=text1[i-1];
			i--;
			j--;
			index--;

		}
		else{
			if(dp[i-1][j]>=dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}

	return str;
}
