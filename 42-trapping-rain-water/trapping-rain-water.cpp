class Solution {
public:
    int trap(vector<int>& height) {

        int leftMax = 0, rightMax = 0, left = 0, right = height.size() - 1,
            totalWater = 0;

        while (left < right) {

            if (height[left] < height[right])

            {
                if (leftMax > height[left]) {
                    totalWater += leftMax- height[left];
                    
                }

                else
                {
                    leftMax = height[left];
                }

                left++;



            } 
            else {
                if (height[right]<rightMax)
                {
                    totalWater+= rightMax-height[right];
                }

                else 
                {
                    rightMax= height[right];
                }

                right--;
            }
        }

        return totalWater;
    }
};