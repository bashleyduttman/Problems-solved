class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int l=0;
        int r=0;
        int cnt=0,maxi=INT_MIN;
        int sum=0;
        int ans=0;
        while(r<customers.size()){
            if(grumpy[r]==1){
                sum+=customers[r];
            }
            else{
                ans+=customers[r];
            }
            if((r-l+1)==k){
                maxi=max(maxi,sum);
                if(grumpy[l]==1){
                    sum-=customers[l];
                }
                l++;

            }
            r++;
        }
        return ans+maxi;
    }
};