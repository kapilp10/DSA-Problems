class Solution {
public:
void backtrack(int col,int n,vector<vector<string>>& res,vector<string>& board)
{
    if(col==n)
    {
        res.push_back(board);
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col]='Q';
            backtrack(col+1,n,res,board);
            board[row][col]='.';
        }
    }

}
bool isSafe(int row,int col,vector<string>& board,int n)
{
    int dupRow=row;
    int dupCol=col;
    while(row>=0 && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }
    row=dupRow;
    col=dupCol;
    while(col>=0)
    {
        if(board[row][col]=='Q') return false;
        col--;
    }
    row=dupRow;
    col=dupCol;
    while(row<n && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}
    int totalNQueens(int n) 
    {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        backtrack(0,n,res,board);
        return res.size();
    }
};