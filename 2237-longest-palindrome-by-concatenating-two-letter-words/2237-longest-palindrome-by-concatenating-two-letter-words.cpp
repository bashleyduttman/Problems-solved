class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp;
        int result=0;
        for(const string&word:words){
            string rev=word;
            reverse(rev.begin(),rev.end());
            if(mpp[rev]){
                result+=4;
                mpp[rev]--;
            }
            else{
                mpp[word]++;
            }
        }
        for(auto it:mpp){
            if(it.first[0]==it.first[1] && it.second>0){
                result+=2;
                break;
            }
        }
        return result;
       

    }
};