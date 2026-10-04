class Solution {
public:
    int calPoints(vector<string>& operations) {

        vector<int>ans;

        for(string &num : operations){
            
            if(num == "C"){
                ans.pop_back();
            }else if(num == "D"){
              ans.push_back(2 * ans.back());
            }else if(num == "+"){
                int n = ans.size();
                ans.push_back(ans[n-1] + ans[n-2]);
            }else{
                ans.push_back(stoi(num));
            }
        }
        int sum = 0;

        for(int num : ans){
            sum = sum + num;
        }
        return sum;
    }
};