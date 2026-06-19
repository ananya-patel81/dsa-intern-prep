class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=nums1.size()-1;
        while(j>=0 && k>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k]=nums2[j]; // kyuki nums2 ke elements ke saaro ko dekhna important hai, agar saare bade bade nums 1 mein aage the, toh woh peechhe chale jaayenge and then the rest of the nums 2 go aage.
                j--;
                k--;
                
                
            }
        }

        
        
    }
};
