//BRUTEFORCE
//TC: O(n^2)
//SC: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            long long prod = 1;
            for(int j=i; j<n; j++){
                prod = prod * nums[j];
                ans = max(ans, prod);
            }
        }

        return ans;
    }
};

//OPTIMAL
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long prefix = 1, suffix = 1;
        long long ans = INT_MIN;

        for(int i = 0; i < n; i++){
            // left to right
            prefix *= nums[i];

            // right to left
            suffix *= nums[n - 1 - i];

            ans = max({ans, prefix, suffix});

            // reset if zero
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
        }

        return ans;
    }
};
