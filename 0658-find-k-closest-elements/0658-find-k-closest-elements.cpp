class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int n = arr.size();
        int right = n -1;
        int size = n;

        while(left <= right && size > k){
                if( abs(x - arr[left]) > abs(x - arr[right])){
                    left++;
                }else{
                    right--;
                }
                size--;
        }
        vector<int>ans;
        for(int i=left;i<=right;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};