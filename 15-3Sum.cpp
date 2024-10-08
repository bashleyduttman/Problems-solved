class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s_et;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int target=nums[i];
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int val=nums[l]+nums[r]+target;
                if(val==0){
                    s_et.insert({target,nums[l],nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if(val>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        
        ans.assign(s_et.begin(),s_et.end());
        return ans;

    }
};