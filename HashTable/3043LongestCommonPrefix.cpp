#include <iostream>
#include <unordered_map>
#include <vector>
class Solution
{
public:
    // RUNTIME:600MS, COMPLEXITY O(N*M), BEATS: 16%

    //TODO: SOLVE THIS USING TRIE DATA STRUCTURE(A TYPE OF SEARCH TREE DATA STRUCTURE   )
    int LongestCommonPrefix(std::vector<int> &arr1, std::vector<int> &arr2)
    {

        std::unordered_map<std::string, bool> prefixMap;
        int maxLength = 0;
        for (int num : arr1)
        {
            std::string str_num = std::to_string(num);
            std::string prefix = "";
            for (char ch : str_num)
            {
                prefix += ch;
                prefixMap[prefix] = true; // yeah this shit exits aight
            }
        }
        for (int num : arr2)
        {
            std::string to_str = std::to_string(num);
            std::string check_prefix = "";
            for (char ch : to_str)
            {
                check_prefix += ch;

                // find method here returns the iterator to that (key, val) pair if key is matched, 
                //and if not found it returns interator just past the last element in the map.
                // so obv if key is found its not going to be matched with prefixMap.end()
                if (prefixMap.find(check_prefix) != prefixMap.end())
                {
                    maxLength = std::max(maxLength, static_cast<int>(check_prefix.length()));
                    // the length method returns a length of a unsigned intreger type but max length is of signed type,
                    // we cannot compare two different type using max function, so either convert unsigned to signed or declare maxLength in other way
                }
            }
        }
        return maxLength;
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