class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;

        int n = num.size();
        int i=0;
        if(k == n){
            return "0";
        }

        while(i<n){
            while(!st.empty() && num[i] < st.top() && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        i = 0;
        while(!ans.empty() && ans[i] == '0'){
            i++;
        }
        ans = ans.substr(i);
        if(ans.empty()) return "0";
        return ans;
    }
};