class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int l=0,r=0,maxi=0;
        unordered_map<int,int> mpp;
        unordered_map<string,int> occurrence;
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp.size()>maxLetters || (r-l+1)>minSize){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size()<=maxLetters && (r-l+1)==minSize){
                occurrence[s.substr(l,r-l+1)]++;
                maxi=max(occurrence[s.substr(l,r-l+1)],maxi);
            }
            r++;
        }
        
        return maxi;
        
    }
   
};