class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return is_matching(s.size()-1,p.size()-1,s,p,dp);
    }
    bool is_matching(int ind,int ind2,string &s,string &p,vector<vector<int>> &dp){
        
        if(ind2>=0 && p[ind2]=='*' && ind2-1<0){
            return true;
        }
        if(ind2>=0 && ind==-1 && p[ind2]=='*'){
            return is_matching(ind,ind2-1,s,p,dp);
        }
        if(ind<0 && ind2<0){
            return true;
        }
        if(ind<0 || ind2<0){
           
            return false;
        }
        if(dp[ind][ind2]!=-1){
            return dp[ind][ind2];
        }
        
        if(s[ind]==p[ind2] || p[ind2]=='?'){
            return dp[ind][ind2]=is_matching(ind-1,ind2-1,s,p,dp);
        }
        cout<<\hello\;
        if(p[ind2]=='*'){
            return dp[ind][ind2]=is_matching(ind,ind2-1,s,p,dp) || is_matching(ind-1,ind2,s,p,dp);
        }
        return false;
    }
};