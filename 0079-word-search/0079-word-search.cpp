class Solution {
public:

    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1}; 

    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int idx){
        if(idx == word.size()) return true;
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;

        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '@';

        for(int k=0;k<4;k++){
            int row = i + dr[k];
            int col = j + dc[k];
            if(dfs(board, word, row, col, idx+1)){
                board[i][j] = temp;
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};