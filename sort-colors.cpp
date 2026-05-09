class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp;   // iske jagah bas teen ints cnt0, cnt1, cnt2 karke unme bhi count store kar sakte ho, in fact that is better. 
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(int i=0; i<mpp[0];i++){
            nums[i]=0;
        }
        for(int i=mpp[0]; i<mpp[0]+ mpp[1];i++){
            nums[i]=1;


        }
        for(int i=mpp[0]+mpp[1]; i<n; i++){
            nums[i]=2;
        }
        
    }
};

//OPTIMAL - DUTCH NATIONAL FLAG ALGORITHM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(int i=0; i<mpp[0];i++){
            nums[i]=0;
        }
        for(int i=mpp[0]; i<mpp[0]+ mpp[1];i++){
            nums[i]=1;


        }
        for(int i=mpp[0]+mpp[1]; i<n; i++){
            nums[i]=2;
        }
        
    }
};
