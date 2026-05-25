class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> sorted_arr=arr;
        sort(sorted_arr.begin(),sorted_arr.end());
        unordered_map<int,int> mpp;
        int rank=1;
        for(int i=0;i<n;i++){
            if(mpp.find(sorted_arr[i])==mpp.end()){
                mpp[sorted_arr[i]]=rank;
                rank++;
            }
        }

        for(int i=0;i<n;i++){
            arr[i]=mpp[arr[i]];
        }

        return arr;
        
    }
};
