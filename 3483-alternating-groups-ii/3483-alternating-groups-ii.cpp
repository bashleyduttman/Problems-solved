class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int l=0,r=0,op=0;
        int n=colors.size();
        for(int i=0;i<k;i++){
            colors.push_back(colors[i]);
        }
        n+=k;
        while(r<n-1){
            
            if(colors[r]==colors[r+1]){
                l=r;
            }
            if(r-l+1>=k){
                op++;
            }
            r++;
        }
        return op;
    }
};