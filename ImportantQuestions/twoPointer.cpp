

// shortest subarray to remove to make array sorted
// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/
class Solution {
    public:
        int findLengthOfShortestSubarray(vector<int>& arr) {
            int n = arr.size();
            int i = 0;
            int j = n - 1;
            while (j > 0 && arr[j] >= arr[j-1])j--;
            if(j==0)return 0;
            // [1,2,3,10 ,4, 2,3,5]
            int ans = j;
            while (i < j  && (i == 0 || arr[i] >= arr[i-1])) {
                while(j<n && arr[i] > arr[j])j++;
                ans = min(ans,j-i-1);
                i++;
            }
            return ans;
        }
    };

    // Next Permutation
    // https://leetcode.com/problems/next-permutation/
    class Solution {
        public:
            void nextPermutation(vector<int>& nums) {
                int n = nums.size();
                int pivot = -1;
                for (int i = n - 1; i > 0; i--) {
                    if (nums[i - 1] < nums[i]) {
                        pivot = i - 1;
                        break;
                    }
                }
                cout << pivot << endl;
                if (pivot == -1) {
                    reverse(nums.begin(), nums.end());
                    return;
                }
                int swapIndex = -1;
                for (int i = n - 1; i >= 0; i--) {
                    if (nums[i] > nums[pivot]) {
                        swapIndex = i;
                        break;
                    }
                }
                cout << swapIndex << endl;
                if (pivot != -1) {
                    swap(nums[swapIndex], nums[pivot]);
                    sort(nums.begin() + pivot+1,nums.end());
                }
            }
        };