class Solution {
private:
    void merge(vector<int>& nums,int low, int mid, int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        while(left<=right && left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right++]);
            }
        }

        while(left<=mid) temp.push_back(nums[left++]);
        while(right<=high) temp.push_back(nums[right++]);
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }

    int countpairs(vector<int>& arr,int low, int mid, int high){
        
        int right=mid+1;
        int cnt=0;
        for(int left=low; left<=mid; left++){
            while(right<=high && (long long)arr[left]>2LL*arr[right]){ //IMPPPP
                right++;
            }
            cnt+=right - (mid+1); //IMPPPPP 
        }

        return cnt; 
    }

    int mergesort(vector<int>& nums, int low, int high){
        if(low>=high) return 0;
        int mid=(low+high)/2;
        int totcnt=0;
        totcnt+=mergesort(nums,low,mid);
        totcnt+=mergesort(nums,mid+1,high);
        totcnt+=countpairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return totcnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=mergesort(nums,0,n-1);
        return cnt;
        
    }
};
