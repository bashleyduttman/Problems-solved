class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0;
        int n = blocks.size();
        int mini=INT_MAX;
        int cnt=0;
        while (r < n) {
            if (blocks[r] == 'W')
                cnt++;
            if (r - l + 1 == k) {
                mini = min(mini, cnt);
                if (blocks[l] == 'W')
                    cnt--;
                l++;
            }
            
            r++;
        }
        return mini;
    }
};