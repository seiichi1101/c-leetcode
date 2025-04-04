#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    int h = haystack.size();
    int n = needle.size();
    for (int i = 0; i <= h - n; i++)
    {
      if (haystack.substr(i, needle.size()) == needle)
      {
        return i;
      }
    }
    return -1;
  }
};

int main()
{
  Solution s;
  // string haystack = "sadbutsad";
  // string needle = "sad";
  // string haystack = "hello";
  // string needle = "ll";
  string haystack = "a";
  string needle = "a";
  // string haystack = "abb";
  // string needle = "abaaa";

  int output = s.strStr(haystack, needle);
  return 0;
}
