class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);  // dp[i] will store the minimum substrings for s[i...n-1]
        dp[n] = 0;  // base case: no substring required for the empty string

        // Precompute powers of 5 up to the maximum possible number (within range of binary string)
        set<int> powersOfFive;
        for (int i = 1; i <= 1e6; i *= 5) {
            powersOfFive.insert(i);
        }

        return minimum(0, s, dp, powersOfFive);
    }
    
    int minimum(int ind, const string& s, vector<int>& dp, const set<int>& powersOfFive) {
        if (ind >= s.size()) {
            return 0;  // No more substrings needed
        }
        if (dp[ind] != -1) {
            return dp[ind];  // Return memoized value
        }
        
        int mini = INT_MAX;
        int currentValue = 0;  // To accumulate binary value
        
        // Try all substrings starting from index 'ind'
        for (int i = ind; i < s.size(); i++) {
            // If the binary number has leading zero, break early
            if (s[ind] == '0' && i == ind) {
                break;
            }
            
            // Shift the currentValue left by 1 and add the new bit (s[i])
            currentValue = (currentValue << 1) | (s[i] - '0');
            
            // If the current value is a power of 5, consider it as a valid substring
            if (powersOfFive.find(currentValue) != powersOfFive.end()) {
                int subResult = minimum(i + 1, s, dp, powersOfFive);
                if (subResult != -1) {
                    mini = min(mini, subResult + 1);  // Add one for the current valid substring
                }
            }
        }
        
        dp[ind] = (mini == INT_MAX) ? -1 : mini;  // Memoize the result for current index
        return dp[ind];
    }
};
