class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxi = 0;
        vector<int> heights(m, 0);  
        
        for (int i = 0; i < n; i++) {
           
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++; 
                } else {
                    heights[j] = 0;  
                }
            }
            
          
            maxi = max(maxi, maximum(heights, m));
        }
        return maxi;
    }

    int maximum(vector<int>& heights, int m) {
        int maxi = 0;
        stack<int> st;
        
        // We iterate over all columns and process the histogram
        for (int i = 0; i <= m; i++) {
            int h = (i == m) ? 0 : heights[i];  // At the end, treat height as 0 for any remaining elements in stack
            
            // Process the stack to compute area
            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxi = max(maxi, height * width);
            }
            st.push(i);
        }
        return maxi;
    }
};
