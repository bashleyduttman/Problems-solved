class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0,z1=0,z2=0;
        for(long long i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            if(nums1[i]==0){
                z1++;
            }
        }
        for(long long j=0;j<nums2.size();j++){
            sum2+=nums2[j];
            if(nums2[j]==0){
                z2++;
            }
        }
        if((z1 ==0 && (abs(sum1-sum2)<z2||sum2>sum1)) || (z2==0 && (abs(sum2-sum1)<z1||sum1>sum2))){
            return -1;
        }
        // if(sum1==sum2){
        //     return sum1+max(z1,z2);
        // }
        if(sum1<sum2){
            
            return sum1+max(z2+sum2-sum1,z1);
        }
        return sum2+max(z1+sum1-sum2,z2);
    }
};