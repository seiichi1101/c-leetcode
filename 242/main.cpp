#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
#include <array>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
    {
      return true;
    }

    array<int, 26> map;
    for (auto &&c : s)
    {
      map[c - 'a']++;
    }

    for (auto &&c : t)
    {
      if (map[c - 'a']-- < 0)
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
  string input1 = "anagram";
  string input2 = "nagaram";
  int output = s.isAnagram(input1, input2);
  return 0;
}
