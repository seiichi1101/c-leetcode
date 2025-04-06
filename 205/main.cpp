#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> smap;
    unordered_map<char, char> tmap;
    for (size_t i = 0; i < s.size(); i++)
    {
      if (smap.find(s[i]) == smap.end() && tmap.find(t[i]) == tmap.end())
      {
        smap[s[i]] = t[i];
        tmap[t[i]] = s[i];
      }
      else if (smap.find(s[i]) != smap.end() && tmap.find(t[i]) != tmap.end())
      {
        if (smap[s[i]] != t[i])
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution s;
  // string input1 = "badc";
  // string input2 = "baba";
  string input1 = "bbbaaaba";
  string input2 = "aaabbbba";
  int output = s.isIsomorphic(input1, input2);
  return 0;
}
