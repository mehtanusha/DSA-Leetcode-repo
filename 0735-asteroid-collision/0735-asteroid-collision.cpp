class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        int n = asteroids.size();

        for(int val : asteroids){
            while(!st.empty() && st.top() > 0 && val < 0 ){
                if(st.top() < abs(val)){
                    st.pop(); //top destroy
                }
                else if(st.top() == abs(val)){
                    st.pop();
                    val = 0;
                    break;
                }
                else{
                    val = 0; //current destroy
                    break;
                }
            }
           if(val != 0){
            st.push(val);
        }
        }

         vector<int>ans(st.size());
       for(int i = st.size()-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
       }
       return ans;
    }
};