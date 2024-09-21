#include <deque>
#include <vector>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq; // Deque to store indices

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove elements from the back of the deque that are less than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);

            // The first valid window starts at index k - 1
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]); // The maximum is at the front of the deque
            }
        }

        return result;
    }
};
