class Solution {
public:
    bool isValid(string s) {
        int cntopen=0;
        stack<char> st;
        for(char ch : s){
            if(st.empty()|| (ch=='(') || (ch=='{')||(ch=='[')){
                cntopen++;
                st.push(ch);
            }
            else{
                if((ch==')') && (st.top()=='(')){
                    cntopen--;
                    st.pop();
                }
                else if((ch=='}') && (st.top()=='{')){
                    cntopen--;
                    st.pop();
                }
                else if((ch==']') && (st.top()=='[')){
                    cntopen--;
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }

        return st.empty();
        
    }
};
