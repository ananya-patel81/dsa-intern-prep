class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n,-1);
        stack<int> mono_st;
        for(int i=2*n-1;i>=0;i--){
            while(!mono_st.empty() && mono_st.top()<=nums[i%n]){
                mono_st.pop();
            }
            
            if(i<n){
                if((!mono_st.empty())){
                    nge[i]=mono_st.top();
                }
            }
            mono_st.push(nums[i%n]);
        }

        return nge;

    }
};
