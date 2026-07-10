class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int i =0; //idx
        int j=n-1; //idx
        int leftmax = 0; //val
        int rightmax = 0; //val
        int water = 0;

        while(i<j){
            if(height[i] <= height[j]){
                if(height[i] <= leftmax){
                    water = water + (leftmax - height[i]);
                } else{
                    leftmax = height[i];
                }
                i++;
            }
         else{
                if(height[j] <= rightmax){
                    water =  water + (rightmax - height[j]);
                }else{
                    rightmax = height[j];
                }
                j--;
            }
        }
        return water;
    }
};