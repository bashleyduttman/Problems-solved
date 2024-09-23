class Solution {
public:
    int countPrimes(int n) {
        vector<int> value(n);
        int cnt=0;
        for(int i=2;i*i<=n;i++){
            int num=i*i;
            while(num<n){
                value[num]=-1;
                num=num+i;
            }
        }
        for(int i=2;i<value.size();i++){
            if(value[i]!=-1){
                cnt++;
            }
        }
        return cnt;

    }
};