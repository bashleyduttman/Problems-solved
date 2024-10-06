class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
        for(int i=0;i<piles.size();i++){
            maxi=max(piles[i],maxi);
        }
        
        long long l=1,r=maxi,ans;
        while(l<=r){
            long long mid=(l+(r-l)/2);
           
            long long hours=check(piles,mid);
           
            if(hours<=h){
                ans=mid;
                r=mid-1;
            }
            else{
                
                l=mid+1;
            }
        }
        return ans;

    }
    long long check(vector<int>&piles,int hr){
        long long total_hours=0;
        for(int i=0;i<piles.size();i++){
            total_hours += ceil(static_cast<double>(piles[i]) / hr);

        }
        return total_hours;
    }
};