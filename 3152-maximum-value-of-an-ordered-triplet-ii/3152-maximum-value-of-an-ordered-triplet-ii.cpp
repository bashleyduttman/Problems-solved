class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0,res=0,maxdiff=0;
        for(auto it:nums){
            res=max(res,maxdiff*it);
            maxdiff=max(maxdiff,maxi-it);
            maxi=max(maxi,(static_cast<long long>(it)));
        }
        return res;
    }
};