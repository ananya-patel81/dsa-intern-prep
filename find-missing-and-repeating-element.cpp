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

//XOR method optimal approach. 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find repeating and missing numbers
    vector<int> findMissingRepeatingNumbers(vector<int>& nums){
        int n=nums.size();
        int xr=0;
        for(int i=0;i<n;i++){
            xr=xr^nums[i];
            xr=xr^(i+1);
        }
        // now xr stores the value with the differentiating bit; We now need to find the differentiating bit.
        int bitno=0;
        while(1){
            if((xr & (1<<bitno))!=0) break;
            else bitno++;
        }
        // bitno is like the place of the differentiation bit. 
        // now we club the numbers from the array and the numbers from 1 to n, to numbers with the bit at bitno place as 1 or 0, and xor them to see which ones are repeating and missing. 
        int zero=0;
        int one=0;
        for(int i=0; i<n;i++){
            if(nums[i] & (1<<bitno)!=0) one = one^nums[i];
            else zero= zero^nums[i];
        }
        for(int i=1; i<n+1;i++){
            if(i & (1<<bitno)!=0) one = one^i;
            else zero= zero^i;
        }
        
        int cnt=0;
        
        for(int i=0; i<n;i++){
            if(nums[i]==zero) cnt++;
        }
        
        if(cnt==0) return {one,zero};
        return {zero,one};
        
        
        
        
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
