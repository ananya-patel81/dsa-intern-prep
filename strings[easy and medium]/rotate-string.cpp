class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=s.size();
        string double_str=s+s;
        if(double_str.find(goal)!= string::npos){
            return true;
        }
        return false;

        
    }
};
