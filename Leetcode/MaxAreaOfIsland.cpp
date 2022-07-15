class Solution {
public:
    bool visited[51][51] = {};
    int roffset[4] = {-1, 0, 0, 1};
    int coffset[4] = {0, -1, 1, 0};
    int m, n; 
    
    bool isIn(int r, int c){
        return r>=0 && r<m && c >=0 && c< n;
    }
    int bfs(int i, int j, vector<vector<int>>& grid){
        int ret = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while(!q.empty()){
            pair<int,int> c = q.front();
            q.pop();
            
            for(int i=0; i<4; i++){
                int nr = c.first + roffset[i];
                int nc = c.second + coffset[i];
                if(!isIn(nr,nc) || visited[nr][nc]) continue;
                if(grid[nr][nc] == 1){
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                    ret++;   
                }
            }
        }
        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ret = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    ret = max(ret, bfs(i, j, grid));
                }
            }
        }
        return ret;
    }
};