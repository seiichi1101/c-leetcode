#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  bool isPalindrome(string s)
  {
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
      if (!isalnum(s[i]))
      {
        i++;
        continue;
      }
      if (!isalnum(s[j]))
      {
        j--;
        continue;
      }

      if (tolower(s[i]) != tolower(s[j]))
      {
        return false;
      }
      i++, j--;
    }

    return true;
  }
};

int main()
{
  Solution s;
  string input = "A man, a plan, a canal: Panama";
  // string input = "race a car";
  // string input = "0P";
  int output = s.isPalindrome(input);
  return output;
}
