class Solution {
public:

    vector<int>previoussmaller(vector<int>&arr){
        stack<int>st1;
        int n = arr.size();
        vector<int>ans(n);

        int i = 0 ;
        while(i<n){
             while(!st1.empty() && arr[st1.top()] > arr[i]){
                st1.pop();
            }
            if(st1.empty()){
                ans[i] =  -1;
            }else{
                ans[i] = st1.top();
            }
            st1.push(i);
            i++;
        }
        return ans;

    }
   
    vector<int> nextsmaller(vector<int>&arr){
        stack<int>st1;
        vector<int>ans(arr.size());
        int i = arr.size() - 1;

        while(i>=0){
            while(!st1.empty() && arr[st1.top()] >= arr[i]){
                st1.pop();
            }
            if(st1.empty()){
                ans[i] =  arr.size();
            }else{
                ans[i] = st1.top();
            }
            st1.push(i);
            i--;
        }
        return ans;
    }
    int sumSubarrayMins(vector<int> &arr) {
        int mod = 1000000007;
        long long  sum  = 0;

        vector<int> left = previoussmaller(arr);
        vector<int>right = nextsmaller(arr);

        for(int i=0;i<arr.size();i++){
          

            long long l = i - left[i];
            long long r = right[i]- i;

            long long  anss = (1LL* arr[i] * l % mod) * r % mod;

            sum = (sum + anss) % mod;;
        }
        return sum;
    }
};
