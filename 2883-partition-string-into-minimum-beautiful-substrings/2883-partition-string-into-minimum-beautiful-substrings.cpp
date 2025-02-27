class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        vector<int>dp(s.size(),-1);
        long long val=minimum(0,s,dp);
        
        return val>=1e7?-1:val;
    }
    long long minimum(int ind,string s,vector<int>&dp){
        if(ind>=s.size()){
            return 0;
        }
        if(s[ind]=='0'){return 1e7;}
        if(dp[ind]!=-1)return dp[ind];
        string temp;
        long long mini=1e7;
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(check(temp)){
               mini=min(mini,minimum(i+1,s,dp)+1);
            }
        }
        return dp[ind]=mini;
    }
    bool check(string& binary_str) {
    
    int num = stoi(binary_str, nullptr, 2); 
    

    if (num <= 0) {
        return false;
    }
    
    while (num % 5 == 0) {
        num /= 5;
    }
    
    return num == 1;
}
};