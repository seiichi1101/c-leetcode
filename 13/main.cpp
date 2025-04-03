#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
  int romanToInt(string s)
  {
    int res = roman.at(s[s.size() - 1]);
    for (int i = s.size() - 2; i > -1; i--)
    {
      if (roman.at(s[i]) >= roman.at(s[i + 1]))
      {
        res += roman.at(s[i]);
      }
      else
      {
        res -= roman.at(s[i]);
      }
    }

    return res;
  }

private:
  static const unordered_map<char, int> roman;
};
const unordered_map<char, int> Solution::roman = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

int main()
{
  Solution s;
  string input = "MCMXCIV";
  int output = s.romanToInt(input);
  return 0;
}
