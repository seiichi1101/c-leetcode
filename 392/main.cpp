#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    int i = 0;
    for (size_t j = 0; j < t.size(); j++)
    {
      if (s[i] == t[j])
      {
        i++;
      }
    }

    return i == s.size();
  }
};

int main()
{
  Solution s;
  string input1 = "abc";
  string input2 = "ahbgdc";

  int output = s.isSubsequence(input1, input2);
  assert(output == true);
  return 0;
}
