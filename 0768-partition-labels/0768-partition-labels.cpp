class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mpp;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(mpp[s[i]]==0){
                mpp[s[i]]=i+1;
            }
            
        }
        int l=0,r=0;
        int maxTime=0;
        vector<int>ans;
       while(r<n){
            if(mpp[s[r]]>maxTime){
                maxTime=mpp[s[r]]-1;
            }
            if(r==maxTime){
                ans.push_back(r-l+1);
                l=r+1;
                maxTime=0;
            }
            r++;
        }
        return ans;
    }
};