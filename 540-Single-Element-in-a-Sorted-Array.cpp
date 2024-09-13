class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        if (r == 0) {
            return nums[0];
        }
        if (nums[0]!=nums[1]) {
            return nums[0];
        }
        if (nums[r]!=nums[r-1]) {
            return nums[r];
        }
        while (l <= r) {
            int mid = (l + (r - l) / 2);
           

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            if ((mid % 2 == 0 && nums[mid + 1] != nums[mid]) ||
                ((mid % 2) == 1 && nums[mid + 1] == nums[mid])) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return 0;
    }
};