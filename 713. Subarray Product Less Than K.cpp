Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.


  // BRUTEFORCE
  class Solution { // TC: O(n^2) | SC: O(1)
  public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            long long product = 1;

            for(int j=i; j<n; j++){
                product = product * nums[j];

                if(product<k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};



//OPTIMAL
class Solution { // TC: O(2N) | SC: O(1)
  public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n = nums.size();
        long long product = 1;
        int cnt = 0;

        while(j < n){
            product = product * nums[j];

            while(product >= k && i<=j){
                product /= nums[i];
                i++;
            }

            cnt = cnt + (j-i+1);
            j++;
        }
        return cnt;
    }
};
