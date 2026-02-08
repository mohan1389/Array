class Solution {
public:
    int majorityElement(vector<int>& nums) {  // BRUTEFORCE TC: O(n^2) | SC: O(1)
        int n = nums.size();
        int cnt = 1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j]) cnt++;
            }

            if(cnt > int(n/2)){
                return nums[i];
                //break;
            }
            cnt = 1;
        }

        return -1;
    }
};


m
