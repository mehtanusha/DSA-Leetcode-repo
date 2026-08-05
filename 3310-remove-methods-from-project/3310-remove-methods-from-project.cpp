class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> calls(n);

        for (auto &call : invocations) {
            int caller = call[0];
            int callee = call[1];

            calls[caller].push_back(callee);
        }

        vector<int> suspicious(n, 0);

        function<void(int)> dfs = [&](int node) {

            suspicious[node] = 1;

            for (int nextMethod : calls[node]) {

                if (!suspicious[nextMethod]) {
                    dfs(nextMethod);
                }
            }
        };

        dfs(k);

        for (auto &call : invocations) {

            int caller = call[0];
            int callee = call[1];

            if (!suspicious[caller] &&
                 suspicious[callee]) {

                vector<int> allMethods;

                for (int i = 0; i < n; i++) {
                    allMethods.push_back(i);
                }

                return allMethods;
            }
        }

        vector<int> remainingMethods;

        for (int i = 0; i < n; i++) {

            if (!suspicious[i]) {
                remainingMethods.push_back(i);
            }
        }

        return remainingMethods;
    }
};