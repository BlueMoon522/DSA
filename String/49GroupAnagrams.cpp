#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution
{
public:
//BEATS: 92.68%, RUNTIME:20ms, COMPLEXITY:O(N∗M∗Log(M))
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::map<std::string, std::vector<std::string>> map;
        std::string temp;
        for (std::string s : strs)
        {
            temp = s;
            std::sort(s.begin(), s.end());
            map[s].push_back(temp);
        }
        std::vector<std::vector<std::string>> res;
       for (const auto& pair : map)
        {
          res.push_back(pair.second);
        }
        return res;
    }
};
int main()
{
    std::vector<std::string> strs = {"",""};
    Solution obj;
    std::vector<std::vector<std::string>> result = obj.groupAnagrams(strs);
    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j)
        {
            std::cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1)
            {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (i < result.size() - 1)
        {
            std::cout << ",";
        }
    }
    std::cout << "]";
return 0;
}