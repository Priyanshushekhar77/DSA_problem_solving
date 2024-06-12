/*
//link->https://leetcode.com/problems/trapping-rain-water/description/


Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int area = 0;  // Variable to store the maximum area
        int i = 0;     // Left pointer
        int j = n - 1; // Right pointer

        while (i < j)
        {

            // Calculate the area based on the smaller height between the two pointers
            int leftht = height[i];
            int rightht = height[j];
            int ht = min(leftht, rightht); // min of two heights
            int width = j - i;
            area = max(area, ht * width);
            // Move the pointer with the smaller height inward
            if (leftht < rightht)
                i++;
            else
                j--;
        }

        return area; // Return the maximum area
    }
};