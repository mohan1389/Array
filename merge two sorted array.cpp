//BRUTEFORCE
//Time Complexity	O(m + n)
// Space Complexity	O(m+n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n, -1);
        int i=0, j=0, ind=0;
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                temp[ind] = nums1[i];
                ind++; i++;
            }
            else{
                temp[ind] = nums2[j];
                ind++; j++;
            }
        }

        while(i<m){
            temp[ind] = nums1[i];
            ind++; i++;
        }
        while(j<n){
            temp[ind] = nums2[j];
            ind++; j++;
        }

        for(int i=0; i<m+n; i++){
            nums1[i] = temp[i];
        }
    }
};


//OPTIMAL
// Time Complexity	O(m + n)
// Space Complexity	O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int i = m - 1;       // last element of nums1 (valid part)
        int j = n - 1;       // last element of nums2
        int k = m + n - 1;   // last position of nums1

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If nums2 still has elements
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
