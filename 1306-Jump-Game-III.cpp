class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        vector<int>dp(arr.size()+1,-1);
        return can_reach(arr,start,dp);
    }
    int can_reach(vector<int> & arr,int ind,vector<int> &dp){
        if(ind<0 || ind>=arr.size()){
            return 0;
        }
        if(arr[ind]==0){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        dp[ind]=0;
        int right=can_reach(arr,ind+arr[ind],dp);
        int left=can_reach(arr,ind-arr[ind],dp);
        dp[ind]=right||left;
        return dp[ind];
    }
};