#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    // RUNTIME:12ms; BEATS:83.39;
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        long long closest = 100000000;
        for (int i = 0; i < nums.size(); i++)
        {
            //no need to check duplicate here, for this we do wanna add same values, and also we are not returning a vector.
            // if (i > 0 && nums[i] == nums[i - 1])
            //     continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(closest - target))
                {
                    closest = sum;
                }

                // our goal is to approach closer to the target
                if (sum > target)
                    k--;
                else if (sum < target)
                    j++;
                else
                    return sum;

                // while (nums[j] == nums[j - 1] && j < k)
                //     j++;
            }
        }
        return closest;
    }
};
int main()
{
    std::vector<int> nums = {4, 0, 5, -5, 3, 3, 0, -4, -5};
    int target = -2;
    Solution obj;
    int result = obj.threeSumClosest(nums, target);
    std::cout << "RESULT IS: " << result << std::endl;
    return 0;
}