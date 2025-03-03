class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>after,before,equal;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                before.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                after.push_back(nums[i]);
            }
            else{
                equal.push_back(nums[i]);
            }
        }
        
        for(int i=0;i<equal.size();i++){
            before.push_back(equal[i]);
        }
        for(int i=0;i<after.size();i++){
            before.push_back(after[i]);
        }
        return before;
    }
};