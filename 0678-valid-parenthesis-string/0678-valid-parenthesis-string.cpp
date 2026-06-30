class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open;
        stack<int>ast; //for asterick 

        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == '*'){
                ast.push(i);
            }
            else{
                if(!open.empty()){
                    open.pop();
                }else if(!ast.empty()){
                    ast.pop();
                } else{
                    return false;
                }
            }
        }
        while(!open.empty() && !ast.empty()){
            if(ast.top() > open.top()){
                open.pop();
                ast.pop();
            }
            else{
                return false;
            }
        }

        if(open.empty()){
            return true;
        }
        return false;
    }
};