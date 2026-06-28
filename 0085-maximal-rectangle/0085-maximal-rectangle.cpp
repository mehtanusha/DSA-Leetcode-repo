class Solution {
public:

    int histogram(vector<int> &heights) {
        stack<int> st;
        int ans = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++) {

            int curheight = (i == n ? 0 : heights[i]);

            while(!st.empty() && heights[st.top()] > curheight) {

                int height = heights[st.top()];
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int maxarea = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            maxarea = max(maxarea, histogram(heights));
        }

        return maxarea;
    }
};