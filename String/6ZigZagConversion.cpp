#include <iostream>
#include <vector>

class ZigZagConversion
{
public:
    // RUNTIME: 12MS, BEATS:55.77%
    std::string convert(std::string &s, int rows)
    {
        std::string res = "";
        if (rows == 1)
            return s; // one row will not make zigzag
        for (int i = 0; i < rows; i++)
        {
            int increment = (rows - 1) * 2;

            // after prinitng the each rows this inner loops exits and new row starts
            for (int j = i; j < s.length(); j += increment)
            {
                // printing first and last row is easy
                res += s[j];

                // now for the middle row we have to find a pattern, that pattern can be derived with the increment and row number.
                // with increment we jump to the same row but different item(which is obv)
                //- 2*i(i is row number and our row starts from 0) gives steps to move from current item to get to the desired item.
                // since we are at j we need to add j + result to get there
                if ((i > 0 && i < rows - 1) && ((j + increment - 2 * i) < s.length()))
                    res += s[j + increment - 2 * i];
            }
        }
        return res;
    }
};
int main()
{
    std::string s = "PAYPALISHIRING";
    int rows = 4;
    ZigZagConversion obj = ZigZagConversion();
    std::string res = obj.convert(s, rows);
    std::cout << "THE RESULT OF A CONVERSION IS: " << res;
    return 0;
}