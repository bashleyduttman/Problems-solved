#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = nums[0], right = nums[0];
        for (int num : nums) {
            if (num < left) left = num;
            if (num > right) right = num;
        }
        while (left < right) {
            int mid = (left + right) >> 1;  
            int count = 0, i = 0, n = nums.size();
            
            while (i < n) {
                if (nums[i] <= mid) {
                    count++;
                    i++;  
                }
                i++;  
                if (count >= k) break;  
            }

            if (count >= k) 
                right = mid;
            else 
                left = mid + 1;
        }

        return left;
    }
};