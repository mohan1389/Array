//BRUTEFORCE
//TC: O(N^2)
//SC: O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum = sum + nums[j];
                if(sum == k) cnt++;
            }
        }
        return cnt;
    }
};


//OPTIMAL
// Time  = O(n)
// Space = O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, cnt = 0, n =nums.size();
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        for(int i=0; i<n; i++){
            sum = sum + nums[i];
           int prefixSum = sum - k;

           if(mpp.find(prefixSum) != mpp.end()){
                cnt += mpp[prefixSum];
            }
           mpp[sum]++;
        }
        return cnt;
    }
};
