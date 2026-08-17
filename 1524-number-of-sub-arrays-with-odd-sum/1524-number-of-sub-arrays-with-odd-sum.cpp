class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int evencount = 1;
        int oddcount = 0;
        int prefixsum = 0;
        int count = 0;

        for(int num : arr){
            prefixsum += num;

            if(prefixsum%2 == 0){
                count += oddcount;
                evencount++;
            }
            else{
                count += evencount;
                oddcount++;
            }
              count = count%MOD;
        }
        return count;
    }
};