class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0, arr[29],maxi=0,max_fre=0;
        while(r<s.size())
        {
            arr[s[r]-'A']+=1;
            max_fre=max(max_fre,arr[s[r]-'A']);
            if(r-l+1-max_fre<=k)
            {
                maxi=max(maxi,r-l+1);
            }else{
                arr[s[l]-'A']-=1;
                l+=1;
            }
            r+=1;
        }
        return maxi;
        
    }
};