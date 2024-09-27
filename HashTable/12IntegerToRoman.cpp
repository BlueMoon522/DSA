#include <iostream>
#include <map>
// TODO: OPTIMIZE THIS SHIT
class Solution
{
public:
    // COMPLEXITY 0LOG(N); RUNTIME:17ms; BEATS: 11%
    std::string toRoman(int num)
    {
        std::map<int, std::string> hmap = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}

        };

        int fact = 1;
        int mod;
        std::string roman = "";
        std::string temp = "";
        int difference;
        while (num > 0)
        {
            mod = num % 10;
            temp = "";

            if (hmap.count(mod * fact) != 0)
            {
                roman.insert(0, hmap[mod * fact]);
            }
            else
            {
                if (mod > 5)
                {
                    temp = hmap[5 * fact];
                    difference = mod * fact - 5 * fact;
                    while (difference > 0)
                    {
                        temp += hmap[fact];
                        difference -= fact;
                    }
                }
                else
                {
                    while (mod * fact > 0)
                    {
                        temp += hmap[fact];
                        mod--;
                    }
                }

                roman.insert(0, temp);
            }

            fact *= 10;
            num = num / 10;
        }
        return roman;
    }
};
int main()
{
    int num = 3999;
    Solution obj = Solution();
    std::string res = obj.toRoman(num);
    std::cout << "RESULT IS: " << res << std::endl;
    return 0;
}
