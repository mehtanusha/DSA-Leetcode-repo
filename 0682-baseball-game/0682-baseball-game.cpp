class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        stack<int> st;

        for (int i = 0; i < operations.size(); i++) {

            string x = operations[i];

            if (x == "+") {
                int one = st.top();
                st.pop();

                int two = st.top();
                st.pop();

                st.push(two);
                st.push(one);
                st.push(one + two);
            }
            else if (x == "D") {
                st.push(2 * st.top());
            }
            else if (x == "C") {
                st.pop();
            }
            else {
                st.push(stoi(x));
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};