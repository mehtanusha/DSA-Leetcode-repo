class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // 1. Count frequency of every task
        vector<int> freq(26, 0);

        for(char task : tasks) {
            freq[task - 'A']++;
        }

        // 2. Put all frequencies into max heap
        priority_queue<int> pq;

        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;

        // 3. Process tasks in groups of n+1
        while(!pq.empty()) {

            vector<int> temp;

            for(int i = 0; i < n + 1; i++) {

                if(!pq.empty()) {

                    int count = pq.top();
                    pq.pop();

                    count--;

                    temp.push_back(count);
                }
            }

            // 4. Put remaining frequencies back into heap
            for(int count : temp) {
                if(count > 0) {
                    pq.push(count);
                }
            }

            // 5. Calculate time
            if(!pq.empty()) {
                time += n + 1;
            }
            else {
                time += temp.size();
            }
        }

        return time;
    }
};