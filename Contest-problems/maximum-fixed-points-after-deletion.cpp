class Solution {
    // vector<int> getdiffarr(vector<int>& nums, int n){
    //     vector<int> diffarr(n);
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==i) diffarr[i]=0;
    //         else if(nums[i]<i) diffarr[i]=i-nums[i];
    //         else diffarr[i]=-1;
    //     }
    //     return diffarr;
    // }
public:
        int maxFixedPoints(vector<int>& A) {
        vector<int> s;
        vector<pair<int, int>> B;
        for (int i = 0; i < A.size(); ++i) {
            if (i >= A[i]) {
                B.push_back({i - A[i], A[i]});
            }
        }
        sort(B.begin(), B.end());

        // LIS
        for (auto& p : B) {
            int x = p.second;
            auto it = lower_bound(s.begin(), s.end(), x);
            if (it == s.end()) {
                s.push_back(x);
            } else {
                *it = x;
            }
        }
        return s.size();
    
    }
};
