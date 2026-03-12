//BRYTEFORCE
//TC: O(n^2)
//SC: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -1e9;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum = sum + nums[j];
                maxSum = max(sum,maxSum);
            }
        }

        return maxSum;
    }
};


//BETTER
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {//KADANE'S ALGORITHM
        if(nums.size() == 1) return nums[0];
        int maxSum = -1e9;
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
           sum = sum + nums[i];
           maxSum = max(maxSum, sum);
           if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};
