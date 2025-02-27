class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return maximum(0,arr,k,dp);
    }
    int maximum(int ind,vector<int>&arr,int k,vector<int>&dp){
        if(ind>=arr.size())return 0;
        int maxi=0;
        int maxvalue=arr[ind];
        if(dp[ind]!=-1)return dp[ind];
        for(int i=0;i<k;i++){
            if(ind+i<arr.size()){
                maxvalue=max(maxvalue,arr[i+ind]);
                maxi=max(maxi,(maxvalue*(i+1))+maximum(ind+i+1,arr,k,dp));
            }
        }
        maxi=max(maxi,arr[ind]+maximum(ind+1,arr,k,dp));
        return dp[ind]=maxi;
    }
};