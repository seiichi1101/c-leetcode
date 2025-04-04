#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int count = 0;
    bool flag = true;
    for (int i = s.size() - 1; i > -1; i--)
    {
      if (s[i] == ' ')
      {
        if (flag)
        {
          continue;
        }
        else
        {
          break;
        }
      }
      else
      {
        count++;
        flag = false;
      }
    }

    return count;
  }
};

int main()
{
  Solution s;
  // string input = "Hello World";
  // string input = "   fly me   to   the moon  ";
  string input = "luffy is still joyboy";
  int output = s.lengthOfLastWord(input);
  return 0;
}
