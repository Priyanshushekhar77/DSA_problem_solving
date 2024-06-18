/* //link-> https://leetcode.com/problems/sliding-window-maximum/description/?envType=list&envId=p0uny51g

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    list<int> temp; // to handle pop from front and back
    int i = 0, j = 0, n = nums.size();
    // handle edge case
    if (k > n)
    {
        ans.push_back(*max_element(nums.begin(), nums.end()));
        return ans;
    }
    while (j < n)
    {
        // calculation->removing element which is less than new upcoming ele arr[j]
        while (temp.size() > 0 && temp.back() < nums[j])
        {
            temp.pop_back();
        }
        // push the ele which is less than temp.back() or if temp is empty
        temp.push_back(nums[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            // first max ele ko push kre
            ans.push_back(temp.front());
            if (temp.front() == nums[i])
                temp.pop_front();
            i++;
            j++;
        }
    }

    return ans;
}