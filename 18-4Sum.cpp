class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> s_et;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            
            for(int j=i+1;j<nums.size();j++){
                long long  prev1=nums[i];
                long long prev2=nums[j];
                long long l=j+1;
                long long r=nums.size()-1;
                while(l<r){
                    long long total=nums[l]+nums[r]+prev1+prev2;
                    if(total==target){
                        s_et.insert({static_cast<int>(prev1),static_cast<int>(prev2),static_cast<int>(nums[l]),static_cast<int>(nums[r])});
                        l++;
                        r--;
                        while(l<nums.size() && nums[l]==nums[l-1]){
                            l++;
                        }
                        while(r<nums.size() && nums[r]==nums[r+1]){
                            r--;
                        }
                    }
                    else if(total>target){
                        

                        r--;
                    }
                    else{
                        
                        l++;
                    }

                }
        }
        }
        
        ans.assign(s_et.begin(),s_et.end());
       
        return ans;
    }
};