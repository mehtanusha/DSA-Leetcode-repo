class Solution {
public:
    int minOperations(string s) {
        int count1 = 0;
        int count2 = 0;

        for(int i=0;i<s.size();i++){
            //010101...
            if(i % 2 == 0 && s[i] != '0'){
                count1++;
            }else if(i % 2 == 1 && s[i] != '1'){
                count1++;
            }

            if(i % 2 == 0 && s[i] != '1'){
                count2++;
            }
            else if(i % 2 == 1 && s[i] != '0'){
                count2++;
            }
        }
        return min(count1,count2);
    }
};