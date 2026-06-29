class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int n = bills.size();
        int i=0;

        while(i<n){
            if(bills[i] == 5){
                five++;
            }else if(bills[i] == 10){
                if(five == 0){
                    return false;
                }
                five--;
                ten++;
            }
            else if(bills[i] == 20){
                if(ten>0 && five >0){
                    ten--;
                    five--;
                } else if(five >=3){
                    five = five - 3;
                } else{
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};