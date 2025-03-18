class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,r=0,maxi=0,cr=0;
        
        while(r<nums.size()){
            while((cr & nums[r] )!=0){
                cr ^= nums[l];
                l++;
            }
            cr|=nums[r];
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;

        
    }
};