// BETTER TC=O(NlogN)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int lastsmaller=INT_MIN;
        int cnt=0;
        int longest=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(lastsmaller==nums[i]-1){
                cnt++;
                lastsmaller=nums[i];
                


            }
            
            else if(lastsmaller+1 < nums[i]){
                cnt=1;
                lastsmaller=nums[i];

            }
            longest = max(longest,cnt);
        }

        

        return longest;

        
        
    }
};



//OPTIMAL TC=O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        int longest=1;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int x=it;
                int cnt=1;
                while(st.find(x+1) != st.end()){
                    x=x+1;
                    cnt=cnt+1;
                }
                longest=max(cnt,longest);
            }
        }
        if(n==0) return 0;


        

        return longest;

        
        
    }
};
