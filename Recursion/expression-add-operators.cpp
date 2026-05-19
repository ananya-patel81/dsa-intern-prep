class Solution {
private:
    void solve(int idx,int target,string& num,string curr,vector<string>& ans,long long prev,long long res){
        if(idx==num.length()){
            if(res==target) ans.push_back(curr);
            return;
        }

        


        for(int i=idx;i<num.length();i++){
            if(i>idx && num[idx]=='0') return; //skipping leading zeroes. Since idx will keep changing because remember this is backtracking and all. So basically idx being zero means ke starting ke elemnts '0' hai. Dry run will explain this better.
            string current_num=num.substr(idx,i-idx+1);
            long long current_num_val=stoll(current_num);
            if(idx==0){
                solve(i+1,target,num,current_num,ans,current_num_val,current_num_val);
            }
            else{
                solve(i+1,target,num,curr+"+"+current_num,ans,current_num_val,res+current_num_val);
                solve(i+1,target,num,curr+"-"+current_num,ans,-current_num_val,res-current_num_val);
                solve(i+1,target,num,curr+"*"+current_num,ans,prev*current_num_val,res-prev+(prev*current_num_val));

            }
            
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string curr="";

        solve(0,target,num,curr,ans,0,0);
        return ans;
        
    }
};
