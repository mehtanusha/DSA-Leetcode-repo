class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;

        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});

        string s = "";

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            if(s.size() < 2){
                s += it.second;
                if(it.first -1 > 0){
                    pq.push({it.first-1,it.second});
                }
            }
            else if(s.size() >= 2){
                char ch1 = s[s.size() -1];
                char ch2 = s[s.size() -2];

                if(it.second == ch1 && it.second == ch2 && ch1 == ch2){
                    if(!pq.empty()){
                        auto nextchar = pq.top();
                        pq.pop();
                        
                        pq.push({it.first,it.second});
                        s += nextchar.second;
                        if(nextchar.first-1 > 0){
                            pq.push({nextchar.first-1,nextchar.second});
                        }
                    }else{
                        return s;
                    }
                }else{
                    s += it.second;
                    if(it.first-1 > 0){
                        pq.push({it.first-1,it.second});
                    }
                }
            }
        }
        return s;
    }
};