class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int maxi=0;
        for(int i=0;i<=n;i++){
            int h=i==n?0:heights[i];
            while(!st.empty() && heights[st.top()]>h){
                int h=heights[st.top()];st.pop();
                int w=st.empty()?i:i-st.top()-1;
                maxi=max(maxi,w*h);
            }
            st.push(i);
        }
        return maxi;
    }
};