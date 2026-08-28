class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int first = -1;
        int last = -1;

        int low = 0;
        int high = n-1;

        while (low <= high){
            int mid = (low+high)/2;
            if (nums[mid] == target){
                first = mid;
                high = mid - 1;
            }else if (target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        low = 0;
        high = n-1;

        while (low <= high){
            int mid = (low+high)/2;
            if (nums[mid] == target){
                last = mid;
                low = mid + 1;
            }else if (target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return {first, last};
    }
};