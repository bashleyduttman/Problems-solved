const int MOD=1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddcnt=0,evencnt=1,res=0,sum=0;

        for(auto it:arr){
            sum+=it;
            if(sum%2==0){
                res+=oddcnt;
                evencnt++;
            }else{
                res+=evencnt;
                oddcnt++;
            }
            res=res%MOD;
        }
        return res;
    }
};