// TWO SUM
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    // COMPLEXITY: O(N^2); RUNTIME: 50MS; BEATS:32.42%
    std::vector<int> two_sum_brute(std::vector<int> &nums, int target)
    {
        std::vector<int> res = {};
        int vec_size = nums.size();
        for (int i = 0; i < vec_size; i++)
        {
            for (int j = i + 1; j < vec_size; j++)
            {
                int sum = nums[i] + nums[j];
                if (sum == target)
                {
                    std::cout << i;
                    std::cout << j;
                    return {i, j};
                }
            }
        }
        return {};
    }
  // COMPLEXITY: O(N); RUNTIME: 10MS; BEATS:48.42%
    std::vector<int> two_sum_hashmap(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> hashmap;
        int vec_size = nums.size();
        for(int i=0;i<vec_size; i++){
            hashmap[nums[i]] = i;
        }
        for(int i =0 ;i<vec_size;i++){
            int difference = target - nums[i];
            if(hashmap[difference] && hashmap[difference]!=i){
                return {hashmap[difference], i};
            }
        }
   return {};

    };
};

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution object = Solution();
    std::vector<int> res = object.two_sum_brute(nums, target);
    return 0;
}
