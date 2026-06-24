class Solution {
  private:
    int merge(vector<int>& arr,int low, int mid,int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        int cnt=0;
        while(left<=right && left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                cnt+=mid-left+1;  //imp observationnnnn
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left++]);
            
        }
        while(right<=high){
            temp.push_back(arr[right++]);
            
        }
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        
        return cnt;
    }
    
    int mergesort(vector<int>& arr, int low, int high){
        if(low>=high) return 0;
        int mid=(low+high)/2;
        int cnt=0;
        cnt+=mergesort(arr,low,mid);
        cnt+=mergesort(arr,mid+1,high);
        cnt+=merge(arr,low,mid,high);
        return cnt;
    }
  public:
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        int cnt=mergesort(arr,0,n-1);
        return cnt;
        
    }
};
