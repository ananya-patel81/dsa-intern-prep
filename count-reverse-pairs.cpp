// solution article link for better understanding: https://takeuforward.org/data-structure/count-reverse-pairs


class Solution {
private: 
    void merge(vector<int>& arr,int low, int mid, int high){
        int left=low;
        int right=mid+1;
        int totcnt=0;
        vector<int> temp;
        while(left<=right && left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=low; i<=high; i++){
            arr[i]=temp[i-low];
        }

        
    }

    int countpairs(vector<int>& arr, int low, int mid, int high){
        int right=mid+1;
        int cnt=0;
        for(int left=low; left<=mid;left++){
            while(right<=high && (long long)arr[left]>2LL*arr[right]){
                right++;
            }
            cnt+=right-(mid+1);

        }
        return cnt;
    }


    int mergesort(vector<int>& arr, int low, int high){
        if(low>=high) return 0;
        int totcnt=0;
        int mid=(low+high)/2;
        totcnt+= mergesort(arr,low,mid);
        totcnt+= mergesort(arr,mid+1,high);
        totcnt+=countpairs(arr,low,mid,high);
        merge(arr,low,mid,high);

        return totcnt;

    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int totcnt=0;
        totcnt+= mergesort(nums,0,n-1);
        return totcnt;

        
    }
};
