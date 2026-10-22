class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;

        int n = nums1.size();

        unordered_map<int,int>mp;

 
        vector<int>ans;
 
        int i = nums2.size() - 1;
 
        while(i>=0){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]]= -1;
            }
            else{
                mp[nums2[i]] = st.top();
              
            }  
            st.push(nums2[i]);
            i--;
        }

        for(int i=0;i<n;i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};