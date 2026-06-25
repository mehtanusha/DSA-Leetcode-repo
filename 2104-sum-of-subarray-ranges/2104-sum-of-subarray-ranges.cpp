class Solution {
public:
     vector<int> getNGL(vector<int>& arr, int n){
        vector<int>res(n);
        stack<int>st;

        int i=0;
        while(i<n){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
            i++;
        }
        return res;
     }

     vector<int> getNGR(vector<int>& arr, int n){
        vector<int>res(n);
        stack<int>st;

        int i=n-1;
        while(i>=0){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
            i--;
        }
        return res;
     }

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
    long long subArrayRanges(vector<int>& nums) {
        long long i=0;
        int n = nums.size();
        vector<int>NSL = getNSL(nums,n);
        vector<int>NSR = getNSR(nums,n);

        vector<int> NGL = getNGL(nums,n);
        vector<int>NGR = getNGR(nums,n);

        long long sumSmaller = 0;
        long long sumGreater = 0;

        while(i<n){
            long long ls = i -NSL[i]; //left sie me kitne elements honge 
            long long rs = NSR[i] - i; //right side me kitne elements honge 
            
            long long lg = i -NGL[i]; //left sie me kitne elements honge 
            long long rg = NGR[i] - i; //right side me kitne elements honge 


            long long totalwaysSmaller = (ls * rs);
            sumSmaller= sumSmaller + (nums[i] *totalwaysSmaller);

            long long totalwaysGreater = (lg * rg);
            sumGreater= sumGreater + (nums[i] *totalwaysGreater);
            i++;

            }
            long long range = sumGreater - sumSmaller;
            return range;
    }
};
