class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
         int n = text1.size();
        int m = text2.size();
        
        // DP table where dp[i][j] represents the length of LCS of text1[0..i-1] and text2[0..j-1]
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return lcs(n - 1, m - 1, text1, text2, dp);
    }

private:
    int lcs(int ind1, int ind2, const string& s1, const string& s2, vector<vector<int>>& dp) {
        // Base case: when either index is out of bounds, the LCS length is 0
        if (ind1 < 0 || ind2 < 0) {
            return 0;
        }

        // If already computed, return the stored result
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }

        // If characters match, move diagonally left-up in the grid
        if (s1[ind1] == s2[ind2]) {
            return dp[ind1][ind2] = 1 + lcs(ind1 - 1, ind2 - 1, s1, s2, dp);
        }

        // If characters don't match, take the maximum LCS by either:
        // 1. Ignoring the current character of s1 and moving left
        // 2. Ignoring the current character of s2 and moving up
        return dp[ind1][ind2] = max(lcs(ind1 - 1, ind2, s1, s2, dp), lcs(ind1, ind2 - 1, s1, s2, dp));
    }
};