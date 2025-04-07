#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cassert>
#include <stack>
using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<int> stack;

    for (auto &&c : s)
    {
      if (c == '(' || c == '{' || c == '[')
      {
        stack.push(c);
      }
      else
      {
        if (stack.empty())
        {
          return false;
        }
        char p = stack.top();
        stack.pop();
        if (c == ')' && p != '(')
        {
          return false;
        }
        else if (c == '}' && p != '{')
        {
          return false;
        }
        else if (c == ']' && p != '[')
        {
          return false;
        }
      }
    }

    return stack.empty();
  }
};

int main()
{
  Solution s;
  string input = "()";
  auto output = s.isValid(input);
  return 0;
}
