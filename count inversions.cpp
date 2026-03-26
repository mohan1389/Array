//BRUTEFORCE
//TC: O(n^2)
//SC: O(1)
class Solution {
public:
   long long int numberOfInversions(vector<int> nums) {
        int n = nums.size(), cnt =0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] > nums[j]) cnt++;
            }
        }

        return cnt;
    }
};


//OPTIMAL
//TC: O(nlogn)
//SC: O(n)
// NOTE: I AM DISTORTING THE ORIGINAL ARRAY. IF INTERVIEWER DON'T WANT THAT COPY THE ORIGINAL ARRAY IN ANOTHER ONE THEN DOO ALL STUFFS
class Solution {
public:
   long long int numberOfInversions(vector<int> nums) {
    int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        cnt += mergeSort(nums, low, mid);      // left half
        cnt += mergeSort(nums, mid + 1, high); // right half
        cnt += merge(nums, low, mid, high);    // merge step

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
                temp.push_back(nums[right]);
                cnt += (mid - left + 1);
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
};
