class Solution {
public:
    int candy(vector<int>& ratings) {
        unordered_map<int, vector<int>> mpp;
        int n = ratings.size(), sum = 0;
        vector<int> wt(n, 0);
        for (int i = 0; i < ratings.size(); i++) {
            mpp[ratings[i]].push_back(i);
        }
        vector<int> temp(ratings.begin(), ratings.end());
        sort(temp.begin(), temp.end());
        set<int> st(temp.begin(), temp.end());
        for (auto it : st) {

            vector<int> arr = mpp[it];
            for (auto ind : arr) {
                int maxi = 0;
                if (ind > 0 && ratings[ind] != ratings[ind - 1]) {
                    maxi = max(wt[ind - 1], wt[ind]);
                }
                if (ind < n - 1 && ratings[ind] != ratings[ind + 1]) {
                    maxi = max(wt[ind + 1], maxi);
                }
                wt[ind] = maxi + 1;
                sum += wt[ind];
            }
        }
        return sum;
    }
};