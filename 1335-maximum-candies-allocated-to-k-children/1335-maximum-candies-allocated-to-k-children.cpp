class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        int l=1;
        int r = *max_element(candies.begin(), candies.end());
       
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(check(candies,mid)<k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return r;
        
    }
    long long check(vector<int> &nums,int mid){
        long long count=0;
        for(int i=0;i<nums.size();i++){
            
                count+=nums[i]/mid;
            
        }
        return count;
    }
};