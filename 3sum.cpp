// 15. 3Sum
// Medium
// Topics
// Companies
// Hint
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result; //initialze result vector to return;
        int n = nums.size();

        if(n < 3) return result;

        sort(nums.begin(), nums.end());

        //fix first element & find the other two using two pointers
        for(int i = 0; i < n-2 ; i++) {
            if(i>0 && nums[i] == nums[i-1]) 
                continue;

            if(nums[i]>0) break; //early termination if smallest value is positive
            
            int target = -nums[i];
                
            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int sum = nums[left] + nums[right];

                if(sum < target) left++; //sum to small, increase left pointer
                else if(sum > target) right--;  //sum too large, vice versa
                else {
                    result.push_back({nums[i], nums[left], nums[right]});

                    //skip dups
                    int leftVal = nums[left];
                    int rightVal = nums[right];
                    while(left < right && nums[left] == leftVal) {
                        left++;
                    }
                    while(left < right && nums[right] == rightVal) { 
                        right--;
                    }
                }
            }
        }

        return result; //return resulting vector
    }
};