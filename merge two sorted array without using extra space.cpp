class Solution {
public:
    void merge(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        int i = n - 1;
        int j = 0;

        // Step 1: Swap elements if needed
        while(i >= 0 && j < m){
            if(arr1[i] > arr2[j]){
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            } else {
                break;
            }
        }

        // Step 2: Sort both arrays
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
    }
};
