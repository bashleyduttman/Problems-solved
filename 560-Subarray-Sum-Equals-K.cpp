#include <unordered_map>
#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum_map;
        int prefix_sum = 0;
        int count = 0;

        prefix_sum_map[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];

          
            if (prefix_sum_map.find(prefix_sum - k) != prefix_sum_map.end()) {
                count += prefix_sum_map[prefix_sum - k];
            }

            prefix_sum_map[prefix_sum]++;
        }

        return count;
    }
};
