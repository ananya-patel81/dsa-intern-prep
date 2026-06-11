//BETTER 
class Solution {
public:
    string countAndSay(int n) {
        // base case is when n=1 return "1"
        if(n==1) return "1";
        string curr=countAndSay(n-1);
        
        string ans="";
        int len=curr.length();
        for(int i=0;i<len;i++){
            int count=1;
            while(i+1<len && curr[i]==curr[i+1]){
                count++;
                i++;
            }

            ans+=to_string(count) + curr[i];
        }
        return ans;
    }
};


//OPTIMAL
class Solution {
public:
    string countAndSay(int n) {
        // base case is when n=1 return "1"
        if(n==1) return "1";
        string res="1";
        for(int i=2;i<=n;i++){
            string next_res="";
            int len=res.length();

            for(int j=0;j<len;j++){
                int count=1;
                while(j+1<len && res[j]==res[j+1]){
                    count++;
                    j++;
                }
                next_res+= to_string(count)+res[j];
            }

            res=next_res;
        }

        return res;
    }
};
