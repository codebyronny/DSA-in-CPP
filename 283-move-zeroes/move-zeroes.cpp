class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        int j=0;
        for (int i=0; i<n; i++){
            if (nums[i]!=0){
                temp[j] = nums[i];
                j++;
            }
        }
        while (j<n){
            temp[j] = 0;
            j++;
        }
        nums = temp;
    }
};