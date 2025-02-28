class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l=0,r=0;
        unordered_set<string>ans;
        unordered_set<string>st;
        string sub;
        while(r<s.size()){
            
            
            sub+=s[r];
            if(r-l==9){
                if(st.find(sub)==st.end()){
                    st.insert(sub);
                }
                else{
                    ans.insert(sub);
                }
               
                sub.erase(0,1);
                l++;

            }
            r++;
        }
        // for(auto it:mpp){
        //     cout<<it.first<<' ';
        //     if(it.second>1){
        //         ans.push_back(it.first);
        //     }
        // }
        vector<string>a(ans.begin(),ans.end());
        return a;
    }
};