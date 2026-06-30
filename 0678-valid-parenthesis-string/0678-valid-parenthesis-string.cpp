class Solution {
public:
    int t[101][101];
    bool isvalid(int i,int open,string s,int n){
        if(i == n){
            if(open == 0) return true;
            return false;
        }
        if(t[i][open] != -1){
            return t[i][open];
        }
        bool valid = false;
        if(s[i] == '('){
            valid |= isvalid(i+1,open+1,s,n);
        }
        else if(s[i] == '*'){
            valid |= isvalid(i+1,open+1,s,n); //consider it open
            valid |= isvalid(i+1,open,s,n); //consider it empty("")
            if(open>0){
                valid |= isvalid(i+1,open-1,s,n);
            }
        }   
        else{
            if(open>0){
                valid |= isvalid(i+1,open-1,s,n);
            }
        }
        return t[i][open] = valid;
    }
    bool checkValidString(string s) {
        memset(t,-1,sizeof(t));
        int n = s.size();
        return isvalid(0,0,s,n);
    }
};