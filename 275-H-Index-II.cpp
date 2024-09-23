class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        
        int l=0,r=citations.size();
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(check(citations,mid)>=mid){
                l=mid+1;
            }
            else{   
                r=mid-1;
            }
        }
        return r;
    }
    int check(vector<int> &nums,int value){
        int cnt=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=value){
                cnt++;
            }
        }
        
        return cnt ;
    }
};
