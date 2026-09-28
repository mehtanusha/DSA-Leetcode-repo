class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        int l = 0;
        int r = 1;
        int ans = 1;
        char prev = ' ';

        while(r < arr.size()) {

            if(arr[r-1] > arr[r]) {

                if(prev == '>') {
                    l = r - 1;
                }

                prev = '>';
            }

            else if(arr[r-1] < arr[r]) {

                if(prev == '<') {
                    l = r - 1;
                }

                prev = '<';
            }

            else {
                l = r;
                prev = ' ';
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};