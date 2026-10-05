class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int curr = 0;

        for(char c : s){
            if(c == '('){
                st.push(curr);
                curr = 0;
            }
            else{
                if(curr == 0){
                    curr = 1;
                }else{
                    curr = 2*curr;
                }
                curr = st.top()+curr;
                st.pop();
            }
        }
        return curr;
    }
};