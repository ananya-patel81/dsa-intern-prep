#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count subarrays with given XOR
    int countSubarrays(vector<int>& A, int k){
        int n=A.size();
        int xori=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            xori=xori ^ A[i];
            if(mpp.find(xori ^ k)!=mpp.end()){
                cnt+=mpp[xori ^ k];
                
            }
            mpp[xori]++;
            
        }
        
        return cnt;
        
    }
};




int main() {
    vector<int> A = {4, 2, 2, 6, 4};
    int k = 6;
    Solution sol;
    cout << sol.countSubarrays(A, k) << endl;
    return 0;
}
