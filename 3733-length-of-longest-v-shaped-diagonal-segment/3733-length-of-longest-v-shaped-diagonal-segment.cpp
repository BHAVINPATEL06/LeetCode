class Solution {
public:
    vector<int>dx={1,1,-1,-1};
    vector<int>dy={1,-1,-1,1};
    vector<vector<vector<vector<int>>>> dp;

    bool isSafe(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m){
            return false;
        }
        return true;
    }
    int recursion(vector<vector<int>>& grid,int k,int val,int dir,int x,int y,int n,int m){
        if(grid[x][y]==val){return 0;}
        if(val==1 && grid[x][y]==0){return 0;}
        if(val==2 && grid[x][y]!=0){return 0;}
        if(val==0 && grid[x][y]!=2){return 0;}
        if(dir>1){return 0;}

        if(dp[x][y][k][dir] != -1) return dp[x][y][k][dir];

        int normal=0;
        int newx=x+dx[k];
        int newy=y+dy[k];
        if(isSafe(newx,newy,n,m)){
            normal=1+recursion(grid,k,grid[x][y],dir,newx,newy,n,m);
        }
        
        int clock=0;
        int cx=x+dx[(k+1)%4];
        int cy=y+dy[(k+1)%4];
        if(isSafe(cx,cy,n,m)){
            clock=1+recursion(grid,(k+1)%4,grid[x][y],dir+1,cx,cy,n,m);
        }

        if(normal==0 && clock==0){dp[x][y][k][dir]=1;}
        else{
            dp[x][y][k][dir] = max(normal,clock);
        }
        return dp[x][y][k][dir];
    }

    int lenOfVDiagonal(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        dp.assign(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(2, -1))));

        bool f=false;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    f=true;
                    for(int k=0;k<4;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(isSafe(x,y,n,m)){
                            ans=max(ans,1+recursion(grid,k,grid[i][j],0,x,y,n,m));
                        }
                    }
                    
                }
            }
        }
        
        return (ans==0 && f==true)? 1:ans;
    }
};