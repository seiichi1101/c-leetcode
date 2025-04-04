#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  int test(vector<int> v)
  {
    return v[0];
  }
};

int main()
{
  Solution s;
  vector<int> input = {1, 2, 3};
  int output = s.test(input);
  assert(output == 0);
  return 0;
}
