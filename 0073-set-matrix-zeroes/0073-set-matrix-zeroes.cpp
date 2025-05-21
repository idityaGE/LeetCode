class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int col_0 = 1;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    if (j != 0)
                        mat[0][j] = 0;
                    else
                        col_0 = 0;
                };

        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++)
                if (mat[i][j] != 0)
                    if (mat[i][0] == 0 || mat[0][j] == 0)
                        mat[i][j] = 0;

        if (mat[0][0] == 0)
            for (int j = 0; j < col; j++)
                mat[0][j] = 0;

        if (col_0 == 0)
            for (int i = 0; i < row; i++)
                mat[i][0] = 0;
    }
};