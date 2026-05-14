class Solution {
public:
    string largestOddNumber(string num) {
        // Start from the back of the string
        for (int i = num.size() - 1; i >= 0; i--) {
            // Check if the character (digit) is odd
            // (num[i] - '0') converts char to int
            if ((num[i] - '0') % 2 != 0) {
                // Return the substring from the beginning to this odd digit
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit is found, return an empty string
        return "";
    }
};
