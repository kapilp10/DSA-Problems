class Solution {
public:
bool isSafe(int col,int row,vector<string>& board,int n)
{
    int dcol=col;
    int drow=row;
    while(row>=0 && col>=0)
    {
        if(board[row][col]=='Q') return false;
        col--;
        row--;
    }

    col=dcol;
    row=drow;

    while(col>=0)
    {
        if(board[row][col]=='Q') return false;
        col--;
    }

    col=dcol;
    row=drow;

    while(row<n && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }

    return true;
}
public:
void backtrack(int col,vector<string>& board,vector<vector<string>>& res,int n)
{
    if(col==n)
    {
        res.push_back(board);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(isSafe(col, row, board, n))
        {
            board[row][col]='Q';
            backtrack(col+1, board, res, n);
            board[row][col]='.';
        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        backtrack(0,board,res,n);
        return res;
    }
};