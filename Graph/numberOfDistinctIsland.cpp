
// WHEN ROTATION IS NOT ALLWED gfg version
class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<int>>&grid, vector<pair<int,int>>&vec,int r0, int c0){
        int n = grid.size(), m = grid[0].size();
        int dir[4][2] = {{0,1},{1,0}, {-1,0},{0,-1}};
        vec.push_back({r-r0, c-c0});
        vis[r][c] = 1;
        for(auto &v:dir){
            int a = r+v[0], b = c+v[1];
            if(a>=0 and b>=0 and a<n and b<m and !vis[a][b] and grid[a][b] == 1){
                dfs(a,b, vis, grid, vec, r0, c0);
            }
        }
    }
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int n = grid.size(), m  = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    vector<pair<int,int>>vec;
                    dfs(i,j, vis, grid,vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//leetcode version
