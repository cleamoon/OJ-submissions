class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unsigned width = obstacleGrid.size();
        unsigned height = obstacleGrid[0].size();
        vector<vector<int>> mat(width, vector<int>(height, 0));
        mat[0][0] = 1;
        for(int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (obstacleGrid[i][j]) {
                    mat[i][j] = 0;
                    continue;
                }
                if (i > 0) mat[i][j] += mat[i - 1][j];
                if (j > 0) mat[i][j] += mat[i][j - 1];
            }
        }
        return mat[width - 1][height - 1];
    }
};