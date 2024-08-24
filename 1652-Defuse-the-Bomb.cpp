class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k==0){
            vector<int> value(code.size(),0);
                return value;
            
        }
        int l=code.size()+k,r=code.size()+k,sum=0,take=0,cnt=0;
        if(k>0){
            l=1,r=1;
        }
            vector<int> value;
            
            while(cnt!=code.size()){
                take++;
                if(l>=code.size()){
                    l=0;
                }
                if(r>=code.size()){
                    r=0;
                }
                sum=sum+code[r];
                if(take>=abs(k)){
                    value.push_back(sum);
                    sum=sum-code[l];
                    l++;
                    cnt++;
                }
                
               
                r++;
            }
            return value;

        
       
        }
         
        
    
};