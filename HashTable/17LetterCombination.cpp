#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution
{
public:
    // TRY WITH BACKTRACKING
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty())
            return {};

        std::map<char, std::string> keyboard = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};

        std::vector<std::string> res;
        std::string mapper = keyboard[digits[0]];

        if (digits.length() == 1)
        {
            std::string mapper = keyboard[digits[0]];
            for (int i = 0; i < mapper.length(); i++)
            {
                res.push_back(std::string(1, mapper[i]));
            }
            return res;
        }

        for (int i = 0; i < mapper.length(); i++)
        {
            int k = 0;
            std::string s;
            s = mapper[i];
            for (int j = 1; j < digits.length(); j++)
            {
         
                    s += keyboard[digits[j]][k];
                
            }
            k++;
            res.push_back(s);
        }

        return res;
    }
};

int main()
{
    std::string digits = "234";
    Solution obj;
    std::vector<std::string> result = obj.letterCombinations(digits);

    std::cout << "Letter Combinations: ";
    for (size_t i = 0; i < result.size(); ++i)
    {
        std::cout << result[i];
        if (i < result.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}
