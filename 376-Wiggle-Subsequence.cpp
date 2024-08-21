class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        bool flg;
        if(nums.size()==1){
            return 1;
        }
        int l=0;
        while(l<nums.size()-1){
            if(nums[l]==nums[l+1]){
                l++;
                continue;
            }
            else if(nums[l]<nums[l+1]){
                flg=true;
                break;
            }
            else{
                flg=false;
                break;
            }
            l++;
    }
    cout<<flg;
    vector<int> dp(nums.size()+1,-1);
        return maximum(0,nums,flg,dp)+1;
        
    }
    int maximum(int ind,vector<int> &nums,bool flg,vector<int> &dp){
        if(ind==nums.size()-1){
            return 0;
        }
        int pick=0;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        if(nums[ind]==nums[ind+1]){
            return maximum(ind+1,nums,flg,dp);
        }
        if(nums[ind]<nums[ind+1] && flg){
            pick=maximum(ind+1,nums,!flg,dp)+1;
        }
        
        
        if(nums[ind]>nums[ind+1] && !flg){
            pick=maximum(ind+1,nums,!flg,dp)+1;
        }
        
        int notpick=maximum(ind+1,nums,flg,dp);
        
        return dp[ind]=max(pick,notpick);

    }
};