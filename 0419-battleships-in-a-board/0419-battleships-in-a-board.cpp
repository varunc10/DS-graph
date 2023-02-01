class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j,char dir){
        if(i<0||j<0||i==board.size()||j==board[0].size()||board[i][j]=='.'){
            return;
        }
        board[i][j]='.';
        if(dir=='l'){    
            dfs(board,i,j-1,'l');
        }
        else if(dir=='r'){    
            dfs(board,i,j+1,'r');
        }
        else if(dir=='u'){    
            dfs(board,i-1,j,'u');
        }
        else{    
            dfs(board,i+1,j,'d');
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='X'){
                    count++;
                    board[i][j]='.';
                    dfs(board,i,j-1,'l');
                    dfs(board,i,j+1,'r');
                    dfs(board,i-1,j,'u');
                    dfs(board,i+1,j,'d');
                }
            }
        }
        return count;
    }
};