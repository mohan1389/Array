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


class Solution {
public:
    int majorityElement(vector<int>& nums) {  // BETTER TC: O(2n) | SC: O(n)
       int n = nums.size();
       unordered_map<int,int> mpp;
       for(int x : nums){
            mpp[x]++;
       }

       for(auto it : mpp){
        if(it.second > int(n/2)) return it.first;
       }

       return -1;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {  // BETTER TC: O(n) | SC: O(1)
        int cnt = 0;
        int number = 0;
        int n =nums.size();

       for(int i=0; i<n; i++){
        if(cnt == 0) number = nums[i];
        if(nums[i] == number) cnt++;
        else cnt--;
       }
       return number;
    }
};


