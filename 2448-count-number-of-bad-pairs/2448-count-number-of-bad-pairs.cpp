class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long cnt = 0;
        long long n = nums.size();
        unordered_map<int, long long> mpp;
        long long total=(n*(n-1))/2;
        
        for (int i = 0; i < n; i++) {
            long long key=nums[i]-i;
            if (mpp.count(key)) {

                cnt += mpp[key];
            
            }
            mpp[key]++;
        }
        return total-cnt;
    }
};