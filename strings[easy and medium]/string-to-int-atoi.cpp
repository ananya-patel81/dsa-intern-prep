class Solution {
private:
    const int INT_MAX_VAL= 2147483647;
    const int INT_MIN_VAL= -2147483648;
    int helper(const string &s, int i, long long num, int sign){
        if(i>=s.size() || !isdigit(s[i])){
            return (int) sign*num;
        }
        num=num*10 + (s[i]-'0');

        if(sign*num>=INT_MAX_VAL) return INT_MAX_VAL;
        if(sign*num<=INT_MIN_VAL) return INT_MIN_VAL;

        return helper(s,i+1,num,sign);
    }
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' ') i++;
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            sign= (s[i]=='-') ? -1 : 1;
            i++;
        }

        return helper(s,i,0,sign);

        
    }
};
