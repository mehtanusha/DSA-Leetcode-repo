class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n){
        vector<int>res(n);
        stack<int>st;

        int i=0;
        while(i<n){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
            i++;
        }
        return res;
     }

     vector<int> getNSR(vector<int>& arr, int n){
        vector<int>res(n);
        stack<int>st;

        int i=n-1;
        while(i>=0){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
            i--;
        }
        return res;
     }

    int sumSubarrayMins(vector<int>& arr) {
        long long mod = 1000000007;
        int n = arr.size();
        //brute force 
        // int sum = 0;
        // for(int i=0;i<n;i++){
        //     int mini = INT_MAX;
        //     for(int j=i;j<n;j++){
        //      mini = min(mini,arr[j]);
        //         sum = (sum + mini)%mod;
        //     }
        // }
        // return sum ;




        //optimal
        int i=0;
        vector<int>NSL = getNSL(arr,n);
        vector<int>NSR = getNSR(arr,n);

        long long sum = 0;
        while(i<n){
            long long ls = i -NSL[i]; //left sie me kitne elements honge 
            
            long long rs = NSR[i] - i; //right side me kitne elements honge 

            long long totalways = (ls * rs) % mod;

            sum = sum + (arr[i] *totalways) % mod;
            i++;

            }
            return sum;
    }
};