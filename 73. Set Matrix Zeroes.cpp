//BRUTEFORCE
//TC: O(n*m) * O(n+m) + O(n*m)
// SC: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    markRow(i,n,matrix);
                    markCol(j,m,matrix);
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == -1e9) matrix[i][j] = 0;
            }
        }
    }

    void markRow(int i, int n, vector<vector<int>>& matrix){
        for(int j=0; j<n; j++){
            if(matrix[i][j] != 0) matrix[i][j] = -1e9;
        }
    }
    void markCol(int j, int m, vector<vector<int>>& matrix){
        for(int i=0; i<m; i++){
            if(matrix[i][j] != 0) matrix[i][j] = -1e9;
        }
    }

};



//BETTER
//TC: O(n*m) + O(n*m)
// SC: O(n) + O(m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m,0);
        vector<int> col(n,0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    col[j] = 1;
                    row[i] = 1;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
