
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        string t=s;
        reverse(t.begin(),t.end());
       
        return lps(0,0,s,t,dp);
        
    }
    int lps(int ind,int ind2,string &str ,string &rev_str,vector<vector<int>> &dp){
        if(ind>=str.size() || ind2>=str.size())
        {
            return 0;
        }
        if(dp[ind][ind2]!=-1)
        {
            return dp[ind][ind2];
        }
        int pick=0;
        if(str[ind]==rev_str[ind2])
        {
            return dp[ind][ind2]=lps(ind+1,ind2+1,str,rev_str,dp)+1;
        }
        return dp[ind][ind2]=max(lps(ind,ind2+1,str,rev_str,dp),lps(ind+1,ind2,str,rev_str,dp));
        

    }
};