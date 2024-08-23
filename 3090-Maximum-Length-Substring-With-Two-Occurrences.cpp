class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> mpp;
        unordered_set<int> set;
        for(auto it:s){
            mpp[it++];
            set.insert(it);
           
        }
        int occurence=2;
        for(auto it:s){
             if(mpp[it]==1){
                occurence=1;
            }
        }
        int l=0,r=0;
        int distinct=set.size();
        int maxi=0;
        unordered_map<int,int> temp;
        unordered_set<int> st;
        while(r<s.size()){
            temp[s[r]]++;
            st.insert(s[r]);
            while(temp[s[r]]>occurence){
                temp[s[l]]--;
                l++;
            }
           
            maxi=max(maxi,r-l+1);
            
            r++;
        }
        return maxi;
        
    }
};