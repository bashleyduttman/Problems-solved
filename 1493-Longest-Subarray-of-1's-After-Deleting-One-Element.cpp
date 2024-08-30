class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0;
        int prev=0;
        int maxi=0;
        int cnt=0;
        while(r<nums.size()){
            if(nums[r]==0){
                cnt++;
            }
            if(cnt>1){
                cnt=1;
                l=prev+1;
            }
            maxi=max(maxi,r-l);
            if(nums[r]==0){
                prev=r;
            }
            r++;
            
        }
        return maxi;
    }
};