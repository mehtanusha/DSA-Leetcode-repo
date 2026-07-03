class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        int first;
        int second;

        for(int i=0;i<n;i++){
            if(tokens[i]=="+" ||tokens[i]=="-"|| tokens[i]=="*"||tokens[i]=="/" ){
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    st.push(second + first);
                }else if(tokens[i] == "-"){
                    st.push(second - first);
                }
                else if(tokens[i] == "*"){
                    st.push(second * first);
                }
                else if(tokens[i] == "/"){
                    st.push(second / first);
                }
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
