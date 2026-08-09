class Solution {
public:
int height = 0;

    void dfs(int node,int dep,vector<vector<int>> &child,vector<int> &depth){
        depth[node] = dep;
        height = max(dep,height);

        for(int c : child[node]){
            dfs(c,dep + 1,child,depth);
        }
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>child(n);
        for(int i=1;i<parent.size();i++){
            child[parent[i]].push_back(i);
        }
        
        vector<int>depth(n);
        dfs(0,1,child,depth);

        double ans = 0;
        for(int i=0;i<n;i++){
            ans = ans +  1LL * nums[i] * (height - depth[i] + 1);
        }
        return ans;
    }
};