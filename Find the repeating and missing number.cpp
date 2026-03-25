//BETTER
//TC: O(n)
//SC: O(n)
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        long long total = n * (n+1)/2;
        long long sum = 0;
        int repeating = 0;

        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
            sum = sum + nums[i];
        }

        for(auto it : mpp){
            if(it.second == 2){
                repeating = it.first;
                break;
            }
        }

        int missing = total - (sum - repeating);

        return {repeating, missing};
    }
};

// this question has 2-optimal approaches one is in ur notebook and another one is by using bit-manipulation jo smj nii aaya
