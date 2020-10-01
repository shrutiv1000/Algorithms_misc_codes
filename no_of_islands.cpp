    class Solution {
    public:
        int ok(int i,int j,int h,int w){
            if(i < h && i >= 0 && j >=0 && j < w) return 1;
                else
                    return 0;
        }

        int numIslands(vector<vector<char>>& grid) {
            if(grid.size() == 0) return 0;
            int h = grid.size();
            int w = grid[0].size();
            int dp[h][w];
            for(int i=0;i<h;i++)
                for(int j = 0;j<w;j++) dp[i][j] = 0;
            int ans = 0;
            vector<pair<int,int>> dir = {
                {-1,0},{0,-1}, {1,0},{0,1}
            };
            queue<pair<int,int>> vis;
            for(int i=0;i<h;i++){
                for(int j = 0;j<w;j++){
                    if(dp[i][j] == 1) continue;
                    if(grid[i][j] == '1' && dp[i][j] == 0){
                        ans++;
                        //cout << i << j << endl;
                        vis.push({i,j});
                        while(!vis.empty()){
                            pair<int,int> x = vis.front();
                            vis.pop();
                            if(dp[x.first][x.second]) continue;
                            dp[x.first][x.second] = 1;
                            for(auto p : dir){
                                if(ok(x.first+p.first,x.second+p.second,h,w)){
                                    if(grid[x.first+p.first][x.second+p.second] == '1') {                                           vis.push({x.first+p.first,x.second+p.second});}

                                }
                            }
                        }
                    }
                }
            }

            return ans;
        }
    };
