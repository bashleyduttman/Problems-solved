#include <vector>\r
#include <unordered_map>\r
#include <algorithm>\r
using namespace std;\r
\r
class Solution {\r
public:\r
    int findLHS(vector<int>& nums) {\r
        unordered_map<int, int> freqMap;\r
        int maxi = 0;\r
\r
       \r
        for (int num : nums) {\r
            freqMap[num]++;\r
        }\r
\r
      \r
        for (auto& entry : freqMap) {\r
            int num = entry.first;\r
            if (freqMap.find(num + 1) != freqMap.end()) {\r
                maxi = max(maxi, freqMap[num] + freqMap[num + 1]);\r
            }\r
        }\r
\r
        return maxi;\r
    }\r
};\r
