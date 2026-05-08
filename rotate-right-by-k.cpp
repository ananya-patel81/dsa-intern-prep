// You need to be careful of the order of reversals. If you are doing k by right, and you want to do the whole array reversal at the end
// then, you need to first reverse 'n-k' elements, and then do reversal of rest of the elments, and then the whole reversal. If you are 
// doing whole reversal first, then do k first elements reversed after whole array reversed and then rest elements reversed. 

// for left shift by k, first reverse k elements [first k elements] , then rest elements and then whole reversal. If doing whole reversal first
// then do 'n-k' reversed, then rest reversed. 

//For Right Shift by $k$:The last $k$ elements move to the front, and the first $n-k$ move to the back.Save the last $k$ elements in a 
//temp vector: [5, 6, 7]Shift the first $n-k$ elements to the right by $k$ positions (in the original array): [1, 2, 3, 4, 5, 6, 7] 
//becomes [X, X, X, 1, 2, 3, 4]Copy temp back into the first $k$ spots: [5, 6, 7, 1, 2, 3, 4]
//For Left Shift by $k$:The first $k$ elements move to the back, and the rest move to the front.Save the first $k$ elements in temp: [1, 2, 3]
//Shift the remaining $n-k$ elements to the left by $k$ positions: [4, 5, 6, 7, X, X, X]Copy temp to the end: [4, 5, 6, 7, 1, 2, 3]

void reverse(int arr[], int start, int end){  // if reverse dunction not given. 
    while(start<=end)
    { 
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=arr[start];
        start++;
        end--;
    }
}
            

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        
        if (n == 0) return; 
        
        k = k % n; // Handle cases where k > n
        if (k == 0) return;

        // 1. Reverse the whole vector
        reverse(nums.begin(), nums.end());
        
        // 2. Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // 3. Reverse the rest
        reverse(nums.begin() + k, nums.end());
        

        
    }
};
