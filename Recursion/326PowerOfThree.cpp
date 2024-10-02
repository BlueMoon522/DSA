#include <iostream>

class Solution
{
public:
//BEATS 100%, 0ms
    bool isPowerOfThree(int n)
    {
        // these two are our base cases our solution is based on these.
        // if given number is a power of 3 and we keep on dividing it by three, it will eventually becomes 1, and thats when we know we found our ans
        if (n == 1)
            return true;

        // if number can no longer be divided and becomes less than 1 at some point, we found our ans
        if (n < 1 || n % 3 != 0)
            return false;

        // now we just need to call the function with n/3
        return isPowerOfThree(n = n / 3);
    }

public:
    bool isPowerOfFour(int n)
    {
        if (n == 1)
            return true;
        if (n < 1 || n % 4 != 0)
            return false;

        return isPowerOfFour(n = n / 4);
    }
};
int main()
{
    int n = 27;
    Solution obj;
    bool result = obj.isPowerOfThree(n);
    std::cout << "RESULT IS: " << result << std::endl;
    return 0;
}