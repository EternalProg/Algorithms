class Solution {
public:
    int longestIdealString(string s, int k) {
        int stringLength = s.size(); // The length of the input string
        int longestLength = 1; // Initialize the longest length with 1, as the minimum ideal string length is 1
        vector<int> dp(stringLength, 1); // Dynamic programming table with a base case of 1 for each character
        unordered_map<char, int> lastOccurrence; // Stores the last occurrence index of each character encountered

        // Initialize the last occurrence for the first character in the string
        lastOccurrence[s[0]] = 0;

        // Iterate over the string starting from the second character
        for (int i = 1; i < stringLength; ++i) {
            char currentChar = s[i]; // Current character being processed

            // Try extending the ideal string including all characters within 'k' distance of current character
            for (char otherChar = 'a'; otherChar <= 'z'; ++otherChar) {
                // If the other character is more than 'k' distance away, skip it
                if (abs(currentChar - otherChar) > k) continue;

                // Check if we have seen the other character before and extend the ideal string length if possible
                if (lastOccurrence.count(otherChar))
                    dp[i] = max(dp[i], dp[lastOccurrence[otherChar]] + 1);
            }

            // Update the last occurrence index for the current character
            lastOccurrence[currentChar] = i;

            // Update the longest length found so far
            longestLength = max(longestLength, dp[i]);
        }

        // Return the length of the longest ideal string found
        return longestLength;
    }
};
