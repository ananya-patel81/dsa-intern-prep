#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to find leaders in an array.
    vector<int> leaders(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int maxi=INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(nums[i]>maxi){
                ans.push_back(nums[i]);
                maxi=nums[i];
                
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};





int main() {
    vector<int> nums = {1, 2, 5, 3, 1, 2};

    // Create an instance of the Solution class
    Solution finder;

    // Get leaders using class method
    vector<int> ans = finder.leaders(nums);

    cout << "Leaders in the array are: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
