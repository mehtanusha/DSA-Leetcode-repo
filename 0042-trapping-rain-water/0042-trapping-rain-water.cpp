class Solution {
public:
    vector<int> getleftmaxArray(vector<int>&height,int n){
        vector<int>leftMax(n);

        leftMax[0] = height[0];
        for(int i=1;i<n;i++){
            leftMax[i] = max(leftMax[i-1],height[i]);
        }
        return leftMax;
    }
     vector<int> getrightmaxArray(vector<int>&height,int n){
        vector<int>rightMax(n);

        rightMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],height[i]);
        }
        return rightMax;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max = getleftmaxArray(height,n);
        vector<int> right_max = getrightmaxArray(height,n);

        int ans =0;
        for(int i= 0;i<n;i++){
            int width = 1;
            int h = min(left_max[i],right_max[i]) - height[i];
            ans = ans + width*h; 
        }
        return ans;
    }
};