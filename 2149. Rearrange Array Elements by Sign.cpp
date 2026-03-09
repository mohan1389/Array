//TC: O(n)
//SC: O(n) - ans array
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        int neg = 1;
        vector<int> ans(n,0);

        for(int i=0; i<n; i++){
            if(nums[i] > 0 && pos < n){
                ans[pos] = nums[i];
                pos = pos + 2;
            }
            else{
                if(neg < n){
                    ans[neg] = nums[i];
                    neg = neg + 2;
                }
            }
        }

        return ans;
    }
};
