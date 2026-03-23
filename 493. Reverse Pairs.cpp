//BRUTEFORCE
//TC: O(n^2)
//SC: O(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] > (long long)2 * nums[j]) cnt++;
            }
        }

        return cnt;
    }
};
