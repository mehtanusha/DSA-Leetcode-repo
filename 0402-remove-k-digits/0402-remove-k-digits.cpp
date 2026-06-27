class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char>st;
        int n = num.size();
        if(n == k){
            return "0";
        }

        int i=0;
        while(i<n){
            if(st.empty()){
                st.push(num[i]);
            }
            else{
                while(k>0 &&  !st.empty() && st.top() > num[i]){
                    st.pop();
                    k--;
                 }
                st.push(num[i]);
            }
            i++;
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        } 
        reverse(ans.begin(),ans.end());
        
        int idx = 0;
        while(idx < ans.size() && ans[idx] == '0'){
            idx++;
        }

        ans = ans.substr(idx);

        if(ans.empty()){
            return "0";
        }

    return ans;
    } 
};