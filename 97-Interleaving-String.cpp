class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size()+s2.size())!=s3.size()){
            return false;
        }
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return isInter(0,0,0,s1,s2,s3,dp);
        
        
    }
    bool isInter(int i,int j ,int k,string &s1,string &s2,string &s3,vector<vector<int>> &dp){
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i<s1.size() && s1[i]==s3[k]){
            if(isInter(i+1,j,k+1,s1,s2,s3,dp)){
                return dp[i][j]=true;
            }
           
            
        }
        if(j<s2.size() && s2[j]==s3[k]){
            if(isInter(i,j+1,k+1,s1,s2,s3,dp)){
                return dp[i][j]=true;
            }
            
        }
        return dp[i][j]=false;
        
    }
};