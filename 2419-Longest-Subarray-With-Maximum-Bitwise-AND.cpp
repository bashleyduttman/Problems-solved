class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,maxi=nums[r],len=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(nums[i],maxi);
        }
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                len=max(len,cnt);
                cnt++;
            }
            else{
                cnt=1;
            }
        }
        return len;
    }
};