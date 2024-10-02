#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
  
    }
};
int main()
{
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution obj;
    std::vector<std::vector<std::string>> result = obj.groupAnagrams(strs);
        std::cout << "["; 
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "["; 
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (i < result.size() - 1) {
            std::cout << ","; 
        }
    }
    std::cout << "]";
    

}