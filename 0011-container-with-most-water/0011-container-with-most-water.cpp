class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i =0;
        int j = n-1;
        int area = 0;
        int ans = 0;

        while(i<j){
            int h = min(height[i],height[j]);
            int width = j-i;

            area = h*width;
            ans = max(ans,area);
            
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};