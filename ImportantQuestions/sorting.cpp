

// 3 sum problem
// https://leetcode.com/problems/3sum/
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());   // -4 -1 -1- 0 1 2
            int n = nums.size();
            for (int i = 0; i < n - 1; i++) {
                int j = i + 1;
                int k = n - 1;
                while (j<k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int>temp(3,0);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[k];
                        ans.push_back(temp);
                        while(j<k && nums[j+1]==nums[j])j++;
                        while(j<k && nums[k-1]==nums[k])k--;
                        j++;
                        k--;
                    } else if (nums[i] + nums[j] + nums[k] > 0) {
                        k--;
                    } else j++;
                }
                while (i + 1 < n && i<j && nums[i] == nums[i +1])i++;
            }
            return ans;
        }
    };

// merge intervals
// https://leetcode.com/problems/merge-intervals/

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(),intervals.end());
            vector<vector<int>>ans;
            vector<int>temp = intervals[0];
            int n = intervals.size();
            for(int i =1;i<n;i++){
                vector<int>curr = intervals[i];
                if(curr[0]<=temp[1]){
                    temp[0]= min(temp[0],curr[0]);
                    temp[1] = max(temp[1],curr[1]);
                }else{
                    ans.push_back(temp);
                    temp = curr;
                }
            }
            if(temp.size() > 0)ans.push_back(temp);
            return ans;
        }
    };


    // 3sum with multiplicity


    class Solution {
        public int threeSumMulti(int[] arr, int target) {
            int mod = 1_000_000_007;
            long result = 0; 
            long[] c = new long[101];
            for(int i : arr) c[i]++;
            
            for(int i = 0; i <= 100; i++) {
                for(int j = i; j <= 100; j++) {
                    int k = target-i-j;
                    if(k<0 || k >100) continue;
                    if(i == j && j==k) {
                        result+= (c[i] * (c[i]-1) * (c[i]-2) /6);
                    }
                    else if(i == j && j != k) {
                        result += ((c[i] * (c[i]-1) /2 ) * c[k]);
                    }
                    else if(i < j && j < k) {
                        result += (c[i] * c[j] * c[k]);
                    }
                }
            }
            return (int)(result%mod);
        }
    }

    // count inversion

    class Solution {
        private:
            // Merge function to merge two sorted halves and count inversions
            int merge(int l, int mid, int r, vector<int>& arr) {
                int n = mid - l + 1; // Size of the left half
                int m = r - mid;     // Size of the right half
                vector<int> left(n), right(m);
        
                // Copy elements to temporary arrays
                for (int i = 0; i < n; i++) {
                    left[i] = arr[l + i];
                }
                for (int j = 0; j < m; j++) {
                    right[j] = arr[mid + 1 + j];
                }
        
                int i = 0, j = 0, k = l;
                int cnt = 0; // Inversion count
        
                // Merge the two halves
                while (i < n && j < m) {
                    if (left[i] <= right[j]) {
                        arr[k++] = left[i++];
                    } else {
                        arr[k++] = right[j++];
                        cnt += (n - i); // Count inversions
                    }
                }
        
                // Copy remaining elements of left half
                while (i < n) {
                    arr[k++] = left[i++];
                }
        
                // Copy remaining elements of right half
                while (j < m) {
                    arr[k++] = right[j++];
                }
        
                return cnt;
            }
        
            // Merge sort function to recursively sort and count inversions
            int mergeSort(vector<int>& arr, int l, int r) {
                int cnt = 0;
                if (l < r) {
                    int mid = l + (r - l) / 2;
                    cnt += mergeSort(arr, l, mid);   // Sort left half
                    cnt += mergeSort(arr, mid + 1, r); // Sort right half
                    cnt += merge(l, mid, r, arr);   // Merge and count inversions
                }
                return cnt;
            }
        
        public:
            // Function to count inversions in the array
            int inversionCount(vector<int>& arr) {
                int n = arr.size();
                return mergeSort(arr, 0, n - 1);
            }
        };
