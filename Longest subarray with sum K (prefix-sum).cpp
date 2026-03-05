//Time complexity: O(n * 1), if map works in O(1) complexity
// in worst case O(n*n)
//Space complexity: O(n)

int longestSubarray(vector<int>& arr, int k) {
    unordered_map<long long,int> mp;
    long long sum = 0;
    int maxLen = 0;

    for(int i = 0; i < arr.size(); i++){

        sum += arr[i];

        if(sum == k)
            maxLen = i + 1;

        if(mp.find(sum - k) != mp.end()){
            int len = i - mp[sum - k];
            maxLen = max(maxLen, len);
        }

        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }

    return maxLen;
}
