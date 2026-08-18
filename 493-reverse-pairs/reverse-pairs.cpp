class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;

        // Brute force is too slow, so use merge sort
        function<void(int, int)> mergeSort = [&](int l, int r) {
            
            if (l >= r)
                return;

            int mid = (l + r) / 2;

            mergeSort(l, mid);
            mergeSort(mid + 1, r);

            // Count reverse pairs
            int j = mid + 1;

            for (int i = l; i <= mid; i++) {
                while (j <= r && (long long)nums[i] > 2LL * nums[j])
                    j++;

                count += j - mid - 1;
            }

            // Merge
            vector<int> temp;
            int i = l;
            j = mid + 1;

            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j])
                    temp.push_back(nums[i++]);
                else
                    temp.push_back(nums[j++]);
            }

            while (i <= mid)
                temp.push_back(nums[i++]);

            while (j <= r)
                temp.push_back(nums[j++]);

            for (int k = l; k <= r; k++)
                nums[k] = temp[k - l];
        };

        mergeSort(0, n - 1);

        return count;
    }
};