//BRUTEFORCE
//TC: O(n^2)
//SC: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), longest = 0;
        for(int i=0; i<n; i++){
            int x = nums[i];
            int cnt = 1;

            while(ls(nums,x+1)){
                x++;
                cnt++;
            }

            longest = max(longest,cnt);
        }
        return longest;
    }
    bool ls(vector<int>& nums, int var){
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == var) return true;
        }
        return false;
    }
};

//BRUTEFORCE
//TC: O(nlogn) + O(n)
//SC: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int lastSmall = -1e9, cnt = 0, n = nums.size(), longest = 0;
        for(int i=0; i<n; i++){
            if(nums[i] - 1 == lastSmall){
                cnt++;
                lastSmall = nums[i];
            }

            else if(nums[i] != lastSmall){//if i am not the part of subsequence, i will be the new subsequence
                cnt = 1;
                lastSmall = nums[i];
            }

            longest = max(longest, cnt);
        }
        return longest;
    }
};
