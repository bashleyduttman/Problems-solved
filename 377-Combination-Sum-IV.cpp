class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> vec(target+1,-1);
        return ways(nums,target,vec);
        
    }
    int ways(vector<int> &n,int target,vector<int> &vec)
    {
        if(target==0)
        {
            return 1;
        }
        int count=0;
        if(vec[target]!=-1)
        {
            return vec[target];
        }
        for(int i=0;i<n.size();i++)
        {
           
            if(n[i]<=target){
                count+=ways(n,target-n[i],vec);
            }
        }
        return vec[target]=count;
    }

};