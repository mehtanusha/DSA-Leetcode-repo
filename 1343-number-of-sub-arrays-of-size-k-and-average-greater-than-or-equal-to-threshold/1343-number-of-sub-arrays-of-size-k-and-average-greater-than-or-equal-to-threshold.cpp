class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0;
        int j=0;
        int n = arr.size();
        int count = 0;
        int  winsum = 0;
        while(j<n){
          winsum += arr[j];

          if(j-i+1 <k){
            j++;
          }
          else if(j-i+1 == k){
            if(winsum/k >= threshold){
                count ++;
            }
            winsum -= arr[i];
            i++;
            j++;
          }
        }
        return count;
    }
};