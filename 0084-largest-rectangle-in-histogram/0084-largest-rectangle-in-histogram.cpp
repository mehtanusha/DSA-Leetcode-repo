class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int ans = 0;

        for(int i=0;i<=n;i++){
            int currheight;
            if(i==n){
                currheight = 0;  //imaginary -∞
            }
            else{
                currheight = heights[i];
            }

            while(!st.empty() && heights[st.top()] > currheight){
                int height = heights[st.top()];
                st.pop();

                int nse = i;
                int pse = st.empty()? -1 : st.top();
                int width = nse - pse -1;
                ans = max (ans,height*width);
            }
            st.push(i);
        }

        return ans;
    }
};