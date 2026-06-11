//BETTER
class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        stack<char> st;
        for(char ch : s){
            if(ch=='(') st.push(ch);
            if(st.empty() && ch==')') cnt++;
            if(!st.empty() && ch==')') st.pop();
        }
        cnt+=st.size();
        return cnt;
        
    }
};

//OPTIMAL
class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int opening=0;
        
        for(char ch : s){
            if(ch=='('){
                opening++;
            } 
            else{
                if(opening>0){
                    opening--;

                }
                else{
                    cnt++;
                }
            }
        
            
        }
        return opening+cnt;
        
        
    }
};
