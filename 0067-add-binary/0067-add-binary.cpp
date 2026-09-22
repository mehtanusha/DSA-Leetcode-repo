class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans = "";
        int i = a.size()-1;
        int j = b.size()-1;

        while(i>=0 || j>=0 || carry){
            int x = 0;
            int y = 0;

            if(i>=0){
                x = a[i]-'0';
            }

            if(j>=0){
                y= b[j]-'0';
            }

            int sum = x^y^carry;
            ans += sum +'0';

            carry = (x&y) | (x&carry) | (y&carry);
            i--;
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};