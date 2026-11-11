class Solution {
public:
    int m = 0;
    int n = 0;


    bool backtrack(vector<vector<char>>& board, int i, int j, int idx, string &word)
    {

        if(idx == word.size())
        {
            return true;
        }

        if( i < 0 || j < 0 || 
            i >= m || j >= n || 
            board[i][j] == '*' || 
            board[i][j] != word[idx])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j]='*';
        if(backtrack(board, i + 1, j, idx + 1, word) || 
            backtrack(board, i - 1, j, idx + 1, word) || 
            backtrack(board, i, j + 1, idx + 1, word) ||
            backtrack(board, i, j - 1, idx + 1, word))
            {
                return true;
            }

        board[i][j] = temp;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> used;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0] && backtrack(board, i, j, 0, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};