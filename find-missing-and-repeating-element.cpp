// Better method is like hash vector, count the frequencies and store in it and then return the ones with frequency 2 and 0;
// Optimal has 2 methods, Mathematical and XOR one. 

// Mathematical one;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find repeating and missing numbers
    vector<int> findMissingRepeatingNumbers(vector<int>& nums){
        int n=nums.size();
        long long s=0;
        long long sN=0;
        long long s2=0;
        long long s2N=0;
        int rep;
        int miss;
        
        for(int i=0;i<n;i++){
            s+=nums[i];
            s2+=(long long)nums[i]*nums[i];
        }
        
        for(int i=1;i<n+1;i++){
            sN+=i;
            s2N+= (long long)i*i ;
            
            
        }
        int rep_miss= s - sN;
        int rep2_miss2= s2 - s2N;
        int repplusmiss= rep2_miss2/rep_miss;
        rep = (repplusmiss+rep_miss)/2;
        miss = (repplusmiss-rep_miss)/2;
        
        return {rep,miss};
        
        
    }
};




int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};
    
    // Create an instance of Solution class
    Solution sol;

    vector<int> result = sol.findMissingRepeatingNumbers(nums);
    
    // Print the repeating and missing numbers found
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}
