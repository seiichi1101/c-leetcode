#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <list>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> findPrimePairs(int n) {

    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;
    // エラトステネスの篩（ふるい） Sieve of Eratosthenes
    for (int i = 2; i <= sqrt(n); i++) {
      // 素数じゃない場合はそれ以前にチェックに含まれているのでスキップ
      // 例えば、4や6はスキップの対象だが、それはすでに2や3でチェックした際に含まれている。なぜなら4や6を素因数分解すると2や3になるからその倍数のチェックも同じということ
      if (primes[i])
        // i*iからスタートしてるのは、それ以前の値のチェックはそれ以前のチェックに含まれているから
        // 例えば、3*3=9の場合3*2はi=2のときにチェックしているし、5*5=25の場合5*2,5*3,5*4は、それ以前にチェックしているという理屈
        for (int j = i * i; j < primes.size(); j += i) {
          primes[j] = false;
        }
    }

    vector<vector<int>> res;
    for (int i = 0; i <= n / 2; i++) {
      if (primes[i] && primes[n - i])
        res.push_back(vector<int>{i, n - i});
    }

    return res;
  }
};

int main() {
  Solution s;
  // auto input1 = 10;
  // auto input1 = 5;
  auto input1 = 999997;
  auto output = s.findPrimePairs(input1);
  return 0;
}
