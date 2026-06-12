class Solution {
private:
    int countPalindrome(string& s, int i, int j){
        int left=i;
        int right=j;
        int count=0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            count+= countPalindrome(s,i,i);
            count+= countPalindrome(s,i,i+1);
        }

        return count;
        
    }
};
