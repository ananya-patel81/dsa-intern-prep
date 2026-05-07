class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int curr= nums[0];
        vector<int> ans;
        ans.push_back(curr);
        int k=1;
        for(int i=0; i<n;i++){
            if(nums[i]!=curr){
                curr=nums[i];
                ans.push_back(curr);
                k++;
            }
            else continue;
        }

        for(int i=0; i<k; i++){
            nums[i]=ans[i];
        }

        return k;
    }
};

//option 2 : Better approach as no need for new array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Handle empty array

        int k = 1; // 'k' keeps track of where to place the next unique element
        
        for (int i = 1; i < n; i++) {
            // If the current element is different from the previous unique element
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i]; // Move it to the 'k-th' position
                k++;               // Increment the count of unique elements
            }
        }

        return k;
    }
};
