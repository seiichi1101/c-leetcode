#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  bool wordPattern(string pattern, string s)
  {
    unordered_map<char, string> pmap;
    unordered_map<string, char> smap;
    size_t i = 0;
    string str;
    for (size_t j = 0; j < s.size() + 1; j++)
    {
      if (s[j] == ' ' || j == s.size())
      {
        if (pmap.find(pattern[i]) == pmap.end() && smap.find(str) == smap.end())
        {
          pmap[pattern[i]] = str;
          smap[str] = pattern[i];
        }
        else
        {
          if (pmap[pattern[i]] != str)
          {
            return false;
          }
        }
        i++;
        str = "";
      }
      else
      {
        str.push_back(s[j]);
      }
    }
    return (i > pattern.size());
  }
};

int main()
{
  Solution s;
  string input1 = "jquery";
  string input2 = "jquery";

  int output = s.wordPattern(input1, input2);
  return 0;
}
