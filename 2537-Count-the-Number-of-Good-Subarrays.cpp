class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l = 0, r = 0;
        long long pair = 0, cnt = 0;
        unordered_map<int, int> mpp;

        while (r < nums.size()) {
           
            pair += mpp[nums[r]];  
            mpp[nums[r]]++;
            r++;

           
            while (pair >= k) {
                cnt += nums.size() - r + 1;   
                mpp[nums[l]]--;
                pair -= mpp[nums[l]]; 
                l++;
            }
        }

        return cnt;
    }
};
