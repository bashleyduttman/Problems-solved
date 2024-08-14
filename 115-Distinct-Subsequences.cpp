class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return distinct_ways(0,0,s,t,dp);

        
    }
    int distinct_ways(int ind,int ind2,string &s,string &s2,vector<vector<int>> &dp)
    {
        
        if(ind>=s.size()|| ind2>=s2.size()){
            if(ind2==s2.size()){
                return 1;
            }
           
            return 0;
        }
        
        if(dp[ind][ind2]!=-1)
        { 
            return dp[ind][ind2];
        }
        int pick=0;
        if(s[ind]==s2[ind2])
        {
            pick=distinct_ways(ind+1,ind2+1,s,s2,dp);

        }
        int notpick=distinct_ways(ind+1,ind2,s,s2,dp);
        return dp[ind][ind2]=notpick+pick;

    }
};