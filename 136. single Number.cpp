class Solution { //BRUTEFORCE | TC:O(n^2) | SC: O(1)
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(nums[i] == nums[j]) cnt++;
            }
            if(cnt == 1){
                return nums[i];
                break;
            }
            else cnt = 0;
        }
        return -1;
    }
};


#include<bits/stdc++.h>
class Solution { //BETTER | TC:O(n) | SC: O(n)
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int x : nums){
            mpp[x]++;
        }

        for(auto it : mpp){
            if(it.second == 1) return it.first;
        }

        return -1;
    }
};


#include<bits/stdc++.h>
class Solution { //optimal | TC:O(n) | SC: O(1)
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
