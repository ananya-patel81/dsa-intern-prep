class Solution {
private:
    void helper(int index, string& s, string& ans, vector<string>& result,unordered_map<char,string>& mpp){
        if(index==s.length()){
            result.push_back(ans);
            return;
        }
        string choice=mpp[s[index]];

        for(int i=0;i<choice.length();i++){
            if(ans.length()<s.length()){
                ans.push_back(choice[i]);
                helper(index+1,s,ans,result,mpp);
                ans.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mpp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        string ans="";
        vector<string> result;
        helper(0,digits,ans,result,mpp);
        return result;
        
    }
};
