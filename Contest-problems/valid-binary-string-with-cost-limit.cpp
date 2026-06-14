//Brute force, accepted if n<=12, TC=O(n.2^n)
class Solution {
private:
    bool consec1Validity(int n){
        int prev=false;
        while(n>0){
            if((prev==false) && ((n&1)==1)){
                prev=true;
            }
            else if((n&1)==0) prev=false;
            else if((prev==true) && ((n&1)==1)){
                return false;
            }
            n=n>>1;
        }
        return true;
    }

    long long pow(int x,int n){
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2==0){
            return pow(x,n/2)*pow(x,n/2);
        }
        return (long long)x*pow(x,n-1);
    }

    int costcalc(int n,int num){
        int i=0;
        int cost=0;
        while(true){
            if(n-i < 1) break;
            if((num&(1<<(n-i-1)))!=0){
                cost+=i;
            }
            i++;
            
        }
        return cost;
    }

    string genBinary(int n, int num){
        string str="";
        int i=0;
        while(true){
            if(n-i<1) break;
            if((num&(1<<(n-i-1)))!=0){
                str+='1';
            }
            else{
                str+='0';
            }
            i++;
        }
        return str;
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        int maxi=pow(2,n);
        for(int num=0;num<maxi;num++){
            if(consec1Validity(num)){
                if(costcalc(n,num)<=k){
                    string str=genBinary(n,num);
                    ans.push_back(str);
                }
            }
        }

        return ans;
        
        
        
    }
};

//OPTIMAL using backtracking O(2^n);
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int n, int k, int index, int current_cost, string& current_str, vector<string>& ans) {
        // Base Case: If the string reaches length n, it's valid!
        if (index == n) {
            ans.push_back(current_str);
            return;
        }

        // Choice 1: Try placing '0' at the current index
        // Placing '0' adds 0 to the cost, so it's always safe to try
        current_str.push_back('0');
        backtrack(n, k, index + 1, current_cost, current_str, ans);
        current_str.pop_back(); // Backtrack

        // Choice 2: Try placing '1' at the current index
        // Condition A: Cannot have consecutive 1s
        // Condition B: Adding this '1' must not push total cost past k
        bool no_consec_ones = current_str.empty() || current_str.back() != '1';
        bool cost_within_limit = current_cost + index <= k;

        if (no_consec_ones && cost_within_limit) {
            current_str.push_back('1');
            backtrack(n, k, index + 1, current_cost + index, current_str, ans);
            current_str.pop_back(); // Backtrack
        }
    }

public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string current_str = "";
        
        // Start recursion from index 0 with an initial cost of 0
        backtrack(n, k, 0, 0, current_str, ans);
        
        return ans;
    }
};
