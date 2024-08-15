class Solution {
public:
    int minDistance(string word1, string word2) {
      
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        
        int len= lps(0,0,word1,word2,dp);
        return word1.size()+word2.size()-(2*len);
      
        
    }
    int lps(int ind,int ind2,string &s,string &s2,vector<vector<int>> &dp)
    {
        if(ind>=s.size() || ind2>=s2.size())
        {
            return 0;
        }
        if(dp[ind][ind2]!=-1)
        {
            return dp[ind][ind2];
        }
        if(s[ind]==s2[ind2])
        {
            return dp[ind][ind2]=lps(ind+1,ind2+1,s,s2,dp)+1;

        }
        return dp[ind][ind2]=max(lps(ind+1,ind2,s,s2,dp),lps(ind,ind2+1,s,s2,dp));
    }
    
};