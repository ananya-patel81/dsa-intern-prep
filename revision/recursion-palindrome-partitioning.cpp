class Solution {
    bool isPalindrome(string s){
        if(s.length()==1) return true;
        int n=s.length();
        for(int i=0;i<(s.length())/2;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }

    void helper(string st,vector<string>& partition, vector<vector<string>>& ans){
        if(st.length()==0){
            ans.push_back(partition);
            return;
        }
        for(int i=0;i<st.length();i++){
            string temp=st.substr(0,i+1);
            if(isPalindrome(temp)) {
                partition.push_back(temp);
                string newst=st.substr(i+1);
                helper(newst,partition,ans);
                partition.pop_back();
            }


        }
    }
public:
    vector<vector<string>> partition(string s) {
        string st=s;
        vector<vector<string>> ans;
        vector<string> partition;
        helper(st,partition,ans); //smart way of using a new string everytime instead of indexes here. 
        return ans;

        
    }
};
