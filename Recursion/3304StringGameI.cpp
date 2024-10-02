#include <iostream>
#include <map>

class Solution
{
public:
    char kthCharacter(int k)
    {
        std::string str = "a";
        while (str.length() < k){
            std::string temp = "";
            for (char ch: str){
                if(ch == 'z') temp.push_back('a');
                else temp.push_back(ch + 1);
            }
            str += temp;
        }
        return str[k - 1];
    }

};

int main()
{
    int k = 5;
    Solution obj;
    char result = obj.kthCharacter(k);
    std::cout << "Result is: " << result;
    return 0;
}