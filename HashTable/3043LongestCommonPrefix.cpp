#include <iostream>
#include <unordered_map>
#include <vector>
class Solution
{
public:
    int LongestCommonPrefix(std::vector<int> &arr1, std::vector<int> &arr2)
    { 
        int count = 0;
        std::unordered_map<std::string, int> hashMap;
    }
};
int main()
{
    std::vector<int> arr1 = {1, 10, 100};
    std::vector<int> arr2 = {1000};
    Solution obj = Solution();
    int result = obj.LongestCommonPrefix(arr1, arr2);
    std::cout << "RESULT IS: " << result;
    return 0;
}