#include <bits/stdc++.h>
using namespace std;

// Class to solve the Aggressive Cows problem
class Solution {
public:
    // Function to check if we can place all cows with at least distance 'd'
    bool canPlace(vector<int>& stalls, int cows, int dist) {
        int n=stalls.size();
        int cowcnt=1;
        int lastpos=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-lastpos>=dist){
                cowcnt++;
                lastpos=stalls[i];
                
            }
            if(cowcnt>=cows) return true;
        }
        return false;
        
        
        
    }
    
    int aggressiveCows(vector<int>& stalls, int cows) {
        sort(stalls.begin(),stalls.end());
        
        int n=stalls.size();
        
        int low=1;
        int high=stalls[n-1]-stalls[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canPlace(stalls,cows,mid)==true){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    
   
    
};

int main() {
    // Example input
    vector<int> stalls = {0, 3, 4, 7, 10,9};
    int cows = 4;

    // Create object of Solution class
    Solution obj;
    // Call function and print result
    cout << obj.aggressiveCows(stalls, cows) << endl;

    return 0;
}
