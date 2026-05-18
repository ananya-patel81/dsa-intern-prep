#include <bits/stdc++.h>
using namespace std;

// Solution class to generate all subsequences using recursion
class Solution {
public:
    // Helper recursive function to generate subsequences
    void helper(string& s, int index, string& subseq, vector<string>& result){
        if(index==s.size()){
            result.push_back(subseq);
            return;
        }
        subseq.push_back(s[index]);
        helper(s,index+1,subseq,result); // including the current element and continuing;
        subseq.pop_back(); // to exclude;
        helper(s,index+1,subseq,result);// excluding the current element and continuing;
        
    }
    vector<string> getSubsequences(string& s){
        int n=s.length();
        vector<string> result;
        string subseq="";
        helper(s,0,subseq,result);
        return result;
    }
};

int main() {
    // Input string
    string s = "ab";

    // Create Solution object
    Solution sol;

    // Get all subsequences
    vector<string> subsequences = sol.getSubsequences(s);

    // Print all subsequences
    for (auto &subseq : subsequences) {
        cout << "\"" << subseq << "\"" << endl;
    }

    return 0;
}
