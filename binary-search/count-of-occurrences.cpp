#include<bits/stdc++.h>
using namespace std;
int count(vector<int>& arr, int n, int x) {
    // checking existence
    
    int low=0;
    int high=n-1;
    int first=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            if(arr[mid]==x) first=mid;
            high=mid-1;
            
        } 
        else if(arr[mid]<x){
            low=mid+1;
        }
        

    }
    if(first==-1) return 0;
    
    
    // finding upper bound 
    low=0;
    high=n-1;
    int upbnd=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=x){
            if(arr[mid]==x){
                upbnd=mid;
                
            }
            low=mid+1;
            
        }   
        else if(arr[mid]>x){
            high=mid-1;
        }
    }
    
    return upbnd-first+1;
};



int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    int ans = count(arr, n, x);
    cout << "The number of occurrences is: "
         << ans << "\n";
    return 0;
}
