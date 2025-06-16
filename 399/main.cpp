#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
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
private:
  double
  backTrackEval(unordered_map<string, unordered_map<string, double>> &graph,
                const string &current, const string &target, double accProduct,
                unordered_set<string> &visited) {
    if (current == target) {
      return accProduct;
    }
    visited.insert(current);
    for (const auto &neighbor : graph[current]) {
      if (!visited.count(neighbor.first)) {
        double result = backTrackEval(graph, neighbor.first, target,
                                      accProduct * neighbor.second, visited);
        if (result != -1.0) {
          return result;
        }
      }
    }
    return -1.0;
  }

public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    vector<double> res;
    unordered_map<string, unordered_map<string, double>> graph;
    for (size_t i = 0; i < equations.size(); i++) {
      auto equation = equations[i];
      string dividend = equation[0];
      string divisor = equation[1];
      double quotient = values[i];

      if (!graph.contains(dividend))
        graph[dividend] = unordered_map<string, double>();
      if (!graph.contains(divisor))
        graph[divisor] = unordered_map<string, double>();

      graph[dividend][divisor] = quotient;
      graph[divisor][dividend] = 1 / quotient;
    }

    for (size_t i = 0; i < queries.size(); i++) {
      auto query = queries[i];
      string dividend = query[0];
      string divisor = query[1];

      if (!graph.contains(dividend) || !graph.contains(divisor))
        res.push_back(-1.0);
      else if (dividend == divisor)
        res.push_back(1.0);
      else {
        unordered_set<string> visited;
        res.push_back(backTrackEval(graph, dividend, divisor, 1, visited));
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<vector<string>> equations{
      vector<string>{"a", "b"},
      vector<string>{"b", "c"},
  };
  vector<double> values{2.0, 3.0};
  vector<vector<string>> queries{
      vector<string>{"a", "c"}, vector<string>{"b", "a"},
      vector<string>{"a", "e"}, vector<string>{"a", "a"},
      vector<string>{"x", "x"},
  };
  auto output = s.calcEquation(equations, values, queries);
  return 0;
}
