class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //efficient O(1)space
	// int rows[9][9]={0}; //rows[5][0] means whether number 1('0'+1) in row 5 has appeared.
	// int cols[9][9]={0}; //cols[3][8] means whether number 9('8'+1) in col 3 has appeared.
	// int blocks[3][3][9]={0};//blocks[0][2][5] means whether number '6' in block 0,2 (row 0~2,col 6~8) has appeared.
	// for(int r=0;r<9;r++)    //traverse board r,c
	// 	for(int c=0;c<9;c++)
	// 		if(board[r][c]!='.'){   //skip all number '.'
	// 			int number=board[r][c]-'1'; //calculate the number's index(board's number minus 1)
	// 			if(rows[r][number]++) return 0; //if the number has already appeared once, return false.
	// 			if(cols[c][number]++) return 0;
	// 			if(blocks[r/3][c/3][number]++) return 0;
	// 		}
	// return 1;
        int N=9;
        unordered_set<char>rowset[N];
        unordered_set<char>colset[N];
        unordered_set<char>sqset[N];
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                if(board[r][c]!='.')
                {
                 char val=board[r][c];
                 int spos=(r/3)*3 + c/3;
                    
                if(rowset[r].count(val) || colset[c].count(val) || sqset[spos].count(val))
                    return false;
                    
                rowset[r].insert(val);
                colset[c].insert(val);
                sqset[spos].insert(val);
                }
            }
        }
        return true;
        
        
    }
};