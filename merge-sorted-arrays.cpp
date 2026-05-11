// Basically, what you need to keep in mind is that both the arrays are SORTED, so you just need to see where they differ. 
// since the first array is like sorted and you add the second one in it in the padded region, default assumption if you had just added
// the second array in the first, that means all the second array elements are larger than the last element of the first array. So to check the 
// assumption, you check the last element of the first array with the last element of second array, and place them accordingly, and iterate both 
// from back. 
// https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space - Solution article 



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(j>=0){ // till all the elements in the second array are checked.
            if(i>=0 && nums1[i]>nums2[j] ){
                nums1[k--]=nums1[i--];   // takes care putting the greater elements in the first array at the end. Notice the pointer j of
              // the second array isn't changed here, since you need to check if the earlier elements are greater than or less than the last or
              // whatever latest element of j is.

            }
            else{
                nums1[k--]=nums2[j--]; // once the elements of the first array are taken care of, as the second array is already sorted, 
              // and by this time k is also at the position where it wants to put the remaining elements, it puts the j elements one by one,
              // and since the arrays are sorted, we just place them.
            }
        }
        // for(int l=m;l<m+n;l++){
        //     nums1[l]=nums2[l-m];
        // }
        // int i=0;
        // int j=m;
        // while(i<=j && j<m+n){
        //     if(i<=j && nums1[i]<=nums1[j]) i++;
        //     else{
        //         swap(nums1[i],nums1[j]);
        //         i++;
                
        //     }
        // }


        
        
    }
};
