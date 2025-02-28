class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l=0,r=0;
        vector<string>ans;
        unordered_map<string,int>mpp;
        string sub;
        while(r<s.size()){
            
            
            sub+=s[r];
            if(r-l==9){
                mpp[sub]++;
                sub.erase(0,1);
                l++;

            }
            r++;
        }
        for(auto it:mpp){
            cout<<it.first<<' ';
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};