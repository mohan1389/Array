//SLIDING WINDOW APPROACH
//TC: O(N) + O(N)
//SC: O(1)

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();
        int l = 0;
        int r = 0;
        long long sum = 0;
        int longest = 0;

        while(r<n){
            sum = sum + nums[r];

            while(sum > k){
                sum = sum - nums[l];
                l++;
            }

            if(sum == k){
                int len = (r-l) + 1;
                longest = max(longest,len);
            }
            r++;
        }
        return longest;
    }
};
