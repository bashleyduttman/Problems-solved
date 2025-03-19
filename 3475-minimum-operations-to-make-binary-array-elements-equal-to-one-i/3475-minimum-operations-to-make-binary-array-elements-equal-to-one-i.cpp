class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (!flipbits(nums, n, i)) {
                    return -1;
                } else {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    bool flipbits(vector<int>& nums, int n, int value) {
        if (value + 2>= n)
            return 0;
        for (int i = value; i < value + 3; i++) {
            if(nums[i]){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
        return 1;
    }
};