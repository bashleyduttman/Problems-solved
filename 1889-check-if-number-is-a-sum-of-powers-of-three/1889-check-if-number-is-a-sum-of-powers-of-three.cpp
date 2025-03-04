class Solution {
public:
    bool checkPowersOfThree(int n) {
        int output=0;
        int temp=n;
        unordered_map<int,int>mpp;
        while(n>0){
            int cnt=calculate(n);
            if(mpp[cnt]==0){
                int ans=pow(3,cnt);
                n=n-ans;
                mpp[cnt]=1;
                output+=ans;
            }
            else{
                return false;
            }
        }
        return temp==output;
        
    }
    int calculate(int value){
    int ans=0;
    int cnt=0;
    while(value>=pow(3,cnt)){
        ans=cnt;
        cnt++;
    }
    return ans;
}
    
};
