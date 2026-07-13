class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";

        vector<int>ans;

        int minlen = to_string(low).size();
        int maxlen = to_string(high).size();

        for(int len = minlen; len<=maxlen; len++){
            for(int start= 0; start<= 9-len;start++){
                string s = digits.substr(start,len);

                int num = stoi(s);

                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};