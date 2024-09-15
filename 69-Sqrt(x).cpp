class Solution {
public:
    int mySqrt(int x) {
        long l=0,r=x,ans=1;
        while(l<=r){
            long mid=(l+(r-l)/2);
            if(mid*mid<=x){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        
        }
        return ans;
    }
};