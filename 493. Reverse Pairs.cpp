//BRUTEFORCE
//TC: O(n^2)
//SC: O(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] > (long long)2 * nums[j]) cnt++;
            }
        }

        return cnt;
    }
};


//OPTIMAL
//TC: O(n) + O(nlogn)
//SC: O(n) - auxiliary stack space
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        cnt += mergeSort(nums, low, mid);      // left half
        cnt += mergeSort(nums, mid + 1, high); // right half
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);    // merge step

        return cnt;
    }

    int merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int cnt = 0;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else { //arr[left] > arr[right]
                if(nums[left] > (long long)2 * nums[right]) cnt += (mid - left + 1);
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Remaining elements
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy back to original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;

        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }

        return cnt;
    }
};
