class Solution {
private :
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis) {
        int n=board.size();
        int m=board[0].size();

        vis[row][col]=1;   //helper func marks boundry O's and their adjacent O's visited
        
        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,+1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 &&nrow<n &&ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,vis );
            }
        }    
    }
public:   
    void solve(vector<vector<char>> & board){

    //------------DFS solution----------
    
        int n=board.size();
        int m=board[0].size();
         
       vector<vector<int>>vis(n,vector<int>(m,0));
        
          for(int j=0;j<m;j++){      //check row 1 and last row have any O not visited
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis );
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,board,vis );
            }
        }
         for(int i=0;i<n;i++){      //check col 1 and last col have any O not visited
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis );
            }
        }
        //iterate again in board and if not visited that will be our surrounded land, make it all "X" 
        for(int i=0;i<n;i++){   
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
    
};