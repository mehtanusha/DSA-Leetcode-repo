class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int i=0;
        int j=0;

        int f1 = -1;
        int f2 = -1;

        int cnt1 =0;
        int cnt2 = 0;

        int ans = 0;

        while(j<n){
            if(f1 == fruits[j]){
                cnt1++;
            }
            else if(f2 == fruits[j]){
                cnt2++;
            }
            else{
                while(cnt1 > 0 && cnt2 > 0){
                    if(f1 == fruits[i]){
                        cnt1--;
                    }else{
                        cnt2--;
                    }
                    i++;
                }
                if(cnt1 == 0){
                    f1 = fruits[j];
                    cnt1 = 1;
                }
                else{
                    f2 = fruits[j];
                    cnt2 = 1;
                }
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};