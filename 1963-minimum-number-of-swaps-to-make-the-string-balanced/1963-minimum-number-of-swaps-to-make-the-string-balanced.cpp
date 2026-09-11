class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int swaps = 0;

        for(char ch : s){
            if(ch == '['){
                balance++;
            }
            else{
                balance--;
            }
            if(balance < 0){
                swaps++;
                balance+=2;
            }
        }
        return swaps;
    }
};