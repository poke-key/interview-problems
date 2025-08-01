class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size(); //get height
        if(n <= 2) return 0; //not enough bars for trapping water

        int leftMax = 0;
        int rightMax = 0;
        int left = 0;
        int right = n - 1;
        int trappedWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // Update leftMax and calculate trapped water
                leftMax = max(leftMax, height[left]);
                trappedWater += leftMax - height[left];
                left++;
            } else {
                // Update rightMax and calculate trapped water
                rightMax = max(rightMax, height[right]);
                trappedWater += rightMax - height[right];
                right--;
            }
        }



        return trappedWater;
        
    }
};