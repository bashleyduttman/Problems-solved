class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long rightsum=0,leftsum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            rightsum+=nums[i];
        }
        for(int i=0;i<nums.size()-1;i++){
            leftsum+=nums[i];
            rightsum-=nums[i];
            if(leftsum>=rightsum){
                cnt++;
            }
        }
        return cnt;
    }
};