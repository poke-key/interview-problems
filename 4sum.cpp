class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());


        for(int i = 0; i < n; i++) {

            if (i>0 && nums[i] == nums[i-1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                if(j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int lo = j + 1, hi = n - 1;
                while (lo < hi) {
                    long long sum = (long long)nums[i] + nums[j] + nums[lo] + nums[hi];

                    if(sum == target) {
                        answer.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        lo += 1;
                        hi -= 1;

                        while (lo < hi && nums[hi] == nums[lo - 1]) {
                            hi -= 1;
                        }

                        while (lo < hi && nums[hi] == nums[hi + 1]) {
                            hi -= 1;
                        }
                    }
                    else if (sum < target) {
                        lo += 1;
                    }
                    else {
                        hi -= 1;
                    }

                }
            }
        }
        return answer;
    }
};