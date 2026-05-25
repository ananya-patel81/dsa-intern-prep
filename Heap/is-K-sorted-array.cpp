class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // Create a vector of pairs to store {element_value, original_index}
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {arr[i], i};
        }
        
        // Sort the vector based on element values
        sort(vec.begin(), vec.end());
        
        // Check if any element shifted by more than k positions
        for (int i = 0; i < n; i++) {
            int original_index = vec[i].second;
            int sorted_index = i;
            
            if (abs(original_index - sorted_index) > k) {
                return "No";
            }
        }
        
        return "Yes";
    }
};
