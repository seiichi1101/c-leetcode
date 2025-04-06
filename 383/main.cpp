#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    // Using HashMap
    //
    // unordered_map<char, int> map = {};
    // for (auto &&m : magazine)
    // {
    //   map[m]++;
    // }

    // for (auto &&r : ransomNote)
    // {
    //   if (map.find(r) != map.end())
    //   {
    //     if (map[r] > 0)
    //     {
    //       map[r]--;
    //     }
    //     else
    //     {
    //       return false;
    //     }
    //   }
    //   else
    //   {
    //     return false;
    //   }
    // }
    // return true;

    for (char c : ransomNote)
    {
      auto it = magazine.find(c);
      if (it != string::npos)
      {
        magazine.erase(it, 1);
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
  string input1 = "aa";
  string input2 = "aab";
  int output = s.canConstruct(input1, input2);
  return 0;
}
