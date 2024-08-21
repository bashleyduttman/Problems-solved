class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int l=0,r=0,result=0,t_distinct=0;
        unordered_set<int> st(nums.begin(),nums.end());
        t_distinct=st.size();
        unordered_map<int,int> freq;
        int dis=0;
        while(r<nums.size()){
            if(freq[nums[r]]==0){
                dis++;
            }
            freq[nums[r]]++;
            while(dis==t_distinct){
                result+=nums.size()-r;
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    dis--;
                }
                l++;

            }
            r++;

            
        }

        return result;
    }
};