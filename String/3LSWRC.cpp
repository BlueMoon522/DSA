// LONGEST SUBSTRING WITHOUT REPEATING CHARACTER

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    // COMPLEXITY: O(N), RUNTIME: 7ms; BEATS: 81.58
    int lenghtOfLongestSubString(std::string &s)
    {
        std::unordered_map<char, int> subStringMap;
        int left = 0;
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            //if no duplicate or duplicate but it is not a part of same substring;
            //eg: "pwwwkew" in kew substring we donot want to be bothered by w being duplicate because it is a completely new substring.
            //we comare duplicate w position with our new search position  which is at k
            //since k index is greater than w index we donot consider this w as duplicate.
            if (subStringMap.count(s[i]) == 0 || subStringMap[s[i]] < left)
            {
                subStringMap[s[i]] = i;
                maxLength = std::max(maxLength, i - left + 1);
            }

           //if duplicate found and duplicate is part of same substring, we have to change our search position
           //the next search position will  start from the char next after duplicate so we increment left by duplicate + 1

            else
            {
                left = subStringMap[s[i]] + 1;
                subStringMap[s[i]] = i;
            }
        }
    }
};
int main()
{
    std::string s = "dvdf";
    Solution obj = Solution();
    int result = obj.lenghtOfLongestSubString(s);
    std::cout << "RESULT IS: \n"
              << result;
    return 0;
}