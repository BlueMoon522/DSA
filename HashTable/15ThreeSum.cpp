#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution
{
public:
    // TIME LIMIT EXCEEDED(FOR 2 QNS) BUT WORKS
    // trying to solve using the concept of two sum  a + b + c = 0 , then a + b = -c, so in first nested loop we store a + b with index of a and b,
    //  we considered duplicated key scenario as well.

    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::unordered_map<int, std::vector<std::pair<int, int>>> hmap;
        std::vector<std::vector<int>> res;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int sum = nums[i] + nums[j];
                hmap[sum].push_back({i, j});
            }
        }
        // in second loop we simply checked if a + b from map with -c from vector if it exists then we have three number such that  a + b + c =0 

        for (int i = 0; i < nums.size(); ++i)
        {
            if (hmap.find(-nums[i]) != hmap.end())
            {
                for (const auto &vec : hmap[-nums[i]])
                {
                    int a = nums[vec.first];
                    int b = nums[vec.second];
                    int c = nums[i];

                    if (vec.first != i && vec.second != i)
                    {
                        std::vector<int> triplet = {a, b, c};
                        std::sort(triplet.begin(), triplet.end());

                        if (std::find(res.begin(), res.end(), triplet) == res.end())
                        {
                            res.push_back(triplet);
                        }
                    }
                }
            }
        }

        return res;
    }

public:
    std::vector<std::vector<int>> threeSumOptimized(std::vector<int> &nums)
    {
        nums.std::sort();
    }
};

int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    Solution obj;
    std::vector<std::vector<int>> result = obj.threeSum(nums);

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
