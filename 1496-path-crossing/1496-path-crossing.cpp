class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>visited;

        int x = 0;
        int y=0;
        visited.insert({0,0});
        for(char ch : path){
            if(ch == 'N') y++;
            if(ch == 'S') y--;
            if(ch == 'E') x++;
            if(ch == 'W') x--;

            if(visited.count({x,y})) return true;
            visited.insert({x,y});
        }
        return false;
    }
};