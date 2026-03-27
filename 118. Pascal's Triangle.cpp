//TC: O(n^2)
//SC: O(n^2) + O(n) - ans array size + temp array
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int row=0; row<numRows; row++){
            vector<int> temp(row+1, 1);
            for(int col=0; col<=row; col++){
                if(col == 0 || row == col) temp[col] = 1;
                else temp[col] = ans[row-1][col] + ans[row-1][col-1];
            }

            ans.push_back(temp);
        }
        return ans;
    }
};
