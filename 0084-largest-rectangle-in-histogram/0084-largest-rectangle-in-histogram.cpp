class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;

        int i=0;
        int ans = 0;
        while(i<=heights.size()){
            int currheight;
            if(i==heights.size()){
                currheight = 0;
            }
            else{
                currheight = heights[i];
            }
            while(!st.empty() && heights[st.top()] > currheight){
                int height = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                ans = max(ans,height * (nse-pse -1));
            }
            st.push(i);
            i++;
        }
        return ans;
    }
};