class Solution {
private:
    bool isPalindrome(string& st){
        if(st.length()==1) return true;
        int n=st.length();
        for(int i=0;i<(n/2);i++){
            if(st[i]!=st[n-i-1]) return false;
        }
        return true;
    }
    void helper(string& st,vector<string>& partitions,vector<vector<string>>& ans){
        if(st.length()==0){
            ans.push_back(partitions);
            return;
        }
        for(int i=0;i<st.length();i++){
            string temp=st.substr(0,i+1);
            if(isPalindrome(temp)){//checking the front partition;
                partitions.push_back(st.substr(0,i+1)); //adding the front partition
                string newSt=st.substr(i+1);
                helper(newSt,partitions,ans); // recurse to the other part. 
                partitions.pop_back(); // to go to other cases and start fresh.


            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        string st=s;
        helper(st,partitions,ans);
        return ans;
        
        
    }
};
