class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        maxarea = 0
        left = 0
        right = n - 1

        while left < right:
            maxarea = max(maxarea, (right - left) * min(height[left], height[right])) #calc area of container formed by the two lines at left and right

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return maxarea      