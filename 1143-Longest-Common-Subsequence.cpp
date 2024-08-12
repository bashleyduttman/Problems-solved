class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int n2 = text2.size();
        
        // DP table where dp[i][j] represents the length of LCS of text1[0..i-1] and text2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(n2 + 1, 0));
        
        // Build the DP table iteratively
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The length of the longest common subsequence is in dp[n][n2]
        return dp[n][n2];
    }
};