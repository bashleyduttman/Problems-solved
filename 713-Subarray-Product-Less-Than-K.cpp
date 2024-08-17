class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,cnt=0,pro=1;
        while(r<nums.size()){
            pro=pro*nums[r];
            while(pro>=k && l<=r){
                
                pro=int(pro/nums[l]);
                l++;
            }
            cnt=cnt+r-l+1;
            r++;
        }
        return cnt;
    }
};