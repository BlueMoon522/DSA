#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution
{
public:
    // COMPLEXITY: O(N^2); RUNTIME:59ms; BEATS:74.14
    std::vector<std::vector<int>> threeSumOptimized(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        int j;
        int k;
        int three_sum;
        for (int i = 0; i < nums.size(); i++)
        {
            // escaping the duplicated. as i remains constant for most of the time when j and k are moved
            // if same i is picked twice j and k can land to previously landed values which they will and duplicate is stored
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            j = i + 1;
            k = nums.size() - 1;
            while (j < k)
            {
                three_sum = nums[i] + nums[j] + nums[k];
                // if > 0, we need to find smaller value for k. since the vec is sorted we can simply decrement k;
                if (three_sum > 0)
                {
                    k--;
                }
                else if (three_sum < 0)
                {
                    j++;
                }
                else
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j = j + 1;
                    // now here also we need to check whether j contains a duplicate or not since i will be constant inside this loop
                    // duplicate in j can  result in duplicate i, j, k   vals.
                    // we donot check for k because if we ensure no duplicate for j , then even if k is duplicate, i, j, k comb will be unique.
                    while (nums[j] == nums[j - 1] && j < k)
                        j++;
                }
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    Solution obj;
    std::vector<std::vector<int>> result = obj.threeSumOptimized(nums);

    for (const auto &triplet : result)
    {
        std::cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i)
        {
            std::cout << triplet[i];
            if (i < triplet.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]\n";
    }

    return 0;
}
