class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int>st(arr.begin(),arr.end());
        int n=arr.size(), maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prev=arr[i];
                int prev2=arr[j];
                int cnt=2;
                while(st.find(prev+prev2)!=st.end()){
                    int temp=prev2;
                    prev2=prev+prev2;
                    prev=temp;
                    cnt++;
                }
                maxi=max(maxi,cnt);
            }
        }
        if(maxi<=2)return 0;
        return maxi;
    }
};