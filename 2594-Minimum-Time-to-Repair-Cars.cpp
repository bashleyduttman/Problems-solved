class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1,r=100000000000000LL;
       
       
        while(l<=r){
            long long mid=(l+(r-l)/2);
            if(check(mid,ranks)>=cars){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;

    }
    long long check(long long value,vector<int> &ranks){
        long long cnt=0;
        
        for(int i=0;i<ranks.size();i++){
            cnt+=sqrt(value/ranks[i]);
        }
        return cnt;
    }
};