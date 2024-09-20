class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        long long l=1;
        long long r=m*n;
        while(l<=r){
            long long mid=(l+(r-l)/2);
            
            if(check(m,n,mid)>=k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;

    }
    int check(int m,int n,int mid){
        int row=1;
        int col=n;
        int cnt=0;
        
        while(row<=m && col>0){
            if((row)*(col)<=mid){
                
                cnt+=col;
                row++;
            }
            else{
                col--;
            }
        }
        
        return cnt;
    }

};