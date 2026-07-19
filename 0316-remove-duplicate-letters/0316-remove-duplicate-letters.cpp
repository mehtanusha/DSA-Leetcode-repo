class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> freq(256, 0);
        vector<bool> visited(256, false);
        stack<char> st;

        for (char ch : s) {
            freq[ch]++;
        }

        for (char ch : s) {

            // Current character ko process kar rahe hain
            freq[ch]--;

            // Agar already stack me hai to skip
            if (visited[ch]) continue;

            // Jab tak:
            // 1. Stack empty nahi hai
            // 2. Stack ka top current se bada hai
            // 3. Top character future me dobara milega
            while (!st.empty() &&
                   st.top() > ch &&
                   freq[st.top()] > 0) {

                visited[st.top()] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch] = true;
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};