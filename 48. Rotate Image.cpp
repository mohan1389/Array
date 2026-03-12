//TC: O(n^2) + O(n^2)
//SC: O(n^2)
//But question asked to modify the same matrix, and in this approach we are using a temp matrix to modify
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int k = n-1;
        vector<vector<int>> temp(n, vector<int>(n,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp[j][k] = matrix[i][j];
            }
            k--;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = temp[i][j];
            }
        }
    }
};
