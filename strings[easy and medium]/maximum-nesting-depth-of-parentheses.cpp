class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int large=0;
        int cnt=0;
        for(char c : s){
            if(c=='('){
                cnt++;
                large=max(large,cnt);
            }
            else if(c==')'){
                cnt--;
            }
            
        }
        return large;
    }
};
