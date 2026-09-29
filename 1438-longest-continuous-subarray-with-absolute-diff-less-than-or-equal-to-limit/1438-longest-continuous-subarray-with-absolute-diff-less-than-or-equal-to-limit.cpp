class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> maxDeque;
        deque<int> minDeque;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            // MAX deque
            while(!maxDeque.empty() &&
                  nums[maxDeque.back()] < nums[right]) {

                maxDeque.pop_back();
            }

            maxDeque.push_back(right);


            // MIN deque
            while(!minDeque.empty() &&
                  nums[minDeque.back()] > nums[right]) {

                minDeque.pop_back();
            }

            minDeque.push_back(right);


            // Window invalid hai
            while(nums[maxDeque.front()] -
                  nums[minDeque.front()] > limit) {

                if(maxDeque.front() == left) {
                    maxDeque.pop_front();
                }

                if(minDeque.front() == left) {
                    minDeque.pop_front();
                }

                left++;
            }


            // Valid window ka maximum length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};