class Solution {
public:
    string countAndSay(int n) {
        return cs( n,\1\);
    }
    string cs(int m,string s){
        if(m==1){
            return s;
        }
        int count=1;
        string rs;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                count++;
            }
            else
            {
                rs+=to_string(count)+s[i];
                count=1;
            }

        }
        rs+=to_string(count)+s[s.size()-1];
        return cs(m-1,rs);
    }
};