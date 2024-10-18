class Solution {
public:
    string longestPalindrome(string s) {
        
        int maxi = 0;
        if(s.size()==1){
            return s;
        }
        string answer = \\;
       for(int i=0;i<s.size()-1;i++){
        lps(i,i,s,maxi,answer);
        lps(i,i+1,s,maxi,answer);
       }
        return answer;
    }
    void lps(int l, int r, string s, int& maxi, string& answer) {
       

        while (l >= 0 && r < s.size() && s[l] == s[r]) {

            l--;
            r++;
        }

       int length=r-l-1;
       if(length>maxi){
        answer=s.substr(l+1,length);
        maxi=length;
       }
    }
};