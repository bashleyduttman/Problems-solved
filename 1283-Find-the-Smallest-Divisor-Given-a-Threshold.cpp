class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=0;
        int mini=nums[0];
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        int l=1,r=maxi;
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(check(nums,mid)<=threshold){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return r+1;
    }
    int check(const vector<int> &nums,int value){
        int total=0;
        for(int i=0;i<nums.size();i++){
            total += ceil(double(nums[i]) / value);

        
    }
        return total;

    }
};