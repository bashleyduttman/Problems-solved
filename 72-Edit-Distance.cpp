class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return min_alter(word1.size(),word2.size(),word1,word2,dp);
    }
    int min_alter(int ind,int ind2,string &s,string &s2,vector<vector<int>> &dp)
    {
        if(ind<0){
            return ind2+1;
        }
        if(ind2<0){
            return ind+1;
        }
        if(dp[ind][ind2]!=-1)
        {
            return dp[ind][ind2];
        }
        if(s[ind]==s2[ind2])
        {
            return dp[ind][ind2]=min_alter(ind-1,ind2-1,s,s2,dp);
        }
        return dp[ind][ind2]=min({min_alter(ind-1,ind2,s,s2,dp),min_alter(ind-1,ind2-1,s,s2,dp),min_alter(ind,ind2-1,s,s2,dp)})+1;
        
    }
};