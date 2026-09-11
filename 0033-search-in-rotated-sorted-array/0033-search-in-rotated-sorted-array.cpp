class Solution {
public:
    int binarySearch(vector<int>& nums,int start,int end,int target){
        while(start<=end){
            int mid = start + (end -start)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid -1;
            }
        }
        return -1;
    }
    int rotated(vector<int>& nums){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start < end){
            int mid = start + (end - start)/2;

            if(nums[mid] > nums[end]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        } return start;
    }
    int search(vector<int>& nums, int target) {
         
        int n = nums.size();

        int index = rotated(nums);
        int ans = -1;

        if (index == 0) { 
            return binarySearch(nums, 0, n - 1, target);
        }

        if(target >= nums[0] && target <= nums[index-1]){
            return binarySearch(nums,0,index-1,target);
        }
        return binarySearch(nums,index,n-1,target);
    }
};
