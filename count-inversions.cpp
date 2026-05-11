#include <bits/stdc++.h>
using namespace std;

// Function to count the number of inversions in an array
// An inversion is a pair (i, j) such that i < j and arr[i] > arr[j]
int merge(vector<int>& arr, int low, int mid,int high){
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
            temp.push_back(arr[right]);
            right++;
            cnt+= mid-left+1;
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

int numberOfInversions(vector<int>& a, int n) {
    int cnt=0;
    cnt=mergesort(a,0,n-1);
    return cnt;
}

int main() {
    vector<int> a = {5, 4, 3, 2, 1};
    int n = a.size();
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions is: " << cnt << endl;
    return 0;
}
