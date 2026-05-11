#include <bits/stdc++.h>
using namespace std;

class FloorCeilFinder {
public:
    // Function to find the floor of x. Floor is the largest element smaller than x.
    int findFloor(int arr[], int n, int x) {
        int low=0;
        int high=n-1;
        int curr;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(arr[mid]<x){
                curr=arr[mid];
                low=mid+1;
                
            }
            else{
                high=mid-1;
            }
        }
        return curr;
        
        
    }
    
    // Function to find the ceiling of x. Ceiling is the smallest element greater than or equal to x.
    int findCeil(int arr[], int n, int x) {
        int low=0;
        int high=n-1;
        int curr;
        while(low<=high){
            int mid=(low+high)/2;
            while(arr[mid]>=x){
                curr= arr[mid];
                high=mid-1;
                mid=(low+high)/2;
            }
            if(arr[mid]<x){
                low=mid+1;
            }
        }
        return curr;

    }
    
    pair<int,int> getFloorAndCeil(int arr[],int n,int x){
        int floor = findFloor(arr,n,x);
        int ceil = findCeil(arr,n,x); 
        return make_pair(floor,ceil);
    }
    
};



int main() {
    int arr[] = {3, 4, 4, 7, 8, 10};
    int n = 6, x = 5;
    FloorCeilFinder finder;
    pair<int, int> ans = finder.getFloorAndCeil(arr, n, x);
    cout << "The floor and ceil are: " << ans.first << " " << ans.second << endl;
    return 0;
}
