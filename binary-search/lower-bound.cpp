#include <bits/stdc++.h>
using namespace std;

// Class containing methods for array operations
class LowerBoundFinder {
public:
    // Function to find lower bound index
    int lowerBound(vector<int> arr, int n, int x) {
        
        int low=0;
        int high=n-1;
        int curr;
        while(low<=high){
            int mid=(low+high)/2;
            while(arr[mid]>=x){
                curr= mid;
                high=mid-1;
                mid=(low+high)/2;
            }
            if(arr[mid]<x){
                low=mid+1;
            }
        }
        return curr;
    }
};

int main() {
    vector<int> arr = {1,2,2,3};
    int n = arr.size();  // Size of the array
    int x = 2;           // Target value

    LowerBoundFinder finder;                  // Create object
    int ind = finder.lowerBound(arr, n, x);   // Find lower bound index

    cout << "The lower bound is the index: " << ind << "\n";

    return 0;
}
