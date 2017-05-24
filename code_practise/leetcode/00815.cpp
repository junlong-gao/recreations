<<<<<<< HEAD
/*
<<<<<<< HEAD
 * [833] Bus Routes
 *
 * https://leetcode.com/problems/bus-routes/description/
 *
 * algorithms
 * Hard (30.39%)
 * Total Accepted:    1.4K
 * Total Submissions: 4.5K
 * Testcase Example:  '[[1,2,7],[3,6,7]]\n1\n6'
 *
 * We have a list of bus routes. Each routes[i] is a bus route that the i-th
 * bus repeats forever. For example if routes[0] = [1, 5, 7], this means that
 * the first bus (0-th indexed) travels in the sequence
 * 1->5->7->1->5->7->1->... forever.
 * 
 * We start at bus stop S (initially not on a bus), and we want to go to bus
 * stop T. Travelling by buses only, what is the least number of buses we must
 * take to reach our destination? Return -1 if it is not possible.
 * 
 * 
 * Example:
 * Input: 
 * routes = [[1, 2, 7], [3, 6, 7]]
 * S = 1
 * T = 6
 * Output: 2
 * Explanation: 
 * The best strategy is take the first bus to the bus stop 7, then take the
 * second bus to the bus stop 6.
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 500.
 * 0 <= routes[i][j] < 10 ^ 6.
 * 
 */
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        
    }
};


/*
TESTS

*/
=======
All stops in a route is a layer of "frontier". Use BFS to search through these layers.
=======
#include <bits/stdc++.h>

<<<<<<< HEAD
/*
1. table : from bus stop to route index
2. visited nodes
3. current frontier

init current frontier with S
mark S to be visited
dist = 0

while frontier is not empty
  for all nodes in the frontier:
    get top; pop top
    for all route in table[top]
      for all nodes in route
        if node is not visited
          if node is destination
            return dist + 1
          push node into queue
      route.clear()
    
  dist += 1
>>>>>>> 2cb9d65 (Update 815.cpp)
*/
=======
>>>>>>> ca578b0 (Update 815.cpp)
class Solution {
    template <typename T>
    using v_t = vector<T>;
    
    template <typename T, typename R>
    using hm_t = unordered_map<T, R>;
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
<<<<<<< HEAD
        unordered_map<int, vector<int>> table;
      for (int i = 0; i < (int)routes.size(); ++i) {
        for (auto busStop : routes[i]) {
          table[busStop].push_back(i);
        }
      }
      
<<<<<<< HEAD
      deque<pair<int, int>> q;
=======
>>>>>>> 2cb9d65 (Update 815.cpp)
      unordered_set<int> visited;
      deque<int> frontier;
      int dist = 0;
      if (S == T) return dist;
      // init
      frontier.push_back(S);
      visited.insert(S);
<<<<<<< HEAD
      while (!q.empty()) {
        auto top = q.front(); q.pop_front();
        if (top.first == T) return top.second;
        
        // how to speed the following up?
        for (const auto & r : in_routes[top.first]) {
          for (const auto & stop : frontiers[r]) {
            if (visited.count(stop) == 0) {
              q.push_back({stop, top.second + 1});
              visited.insert(stop);
=======
      
      while(frontier.size()) {
        deque<int> t;
        swap(t, frontier);
        while (t.size()) {
          auto top = t.front(); t.pop_front();
          for (auto &routeIdx : table[top]) {
            for (auto &s : routes[routeIdx]) {
              if (visited.count(s) == 0) {
                if (s == T) {
                  return dist + 1;
                }
                visited.insert(s);
                frontier.push_back(s);
              }
>>>>>>> 2cb9d65 (Update 815.cpp)
            }
            routes[routeIdx].clear();
          }
        }
        dist++;
      }
      
<<<<<<< HEAD
      return -1;
    }
};
>>>>>>> aa8c761 (Create 815.cpp)
=======
      // cannot find T
      return -1;
    }
};

// To execute C++, please define "int main()"
int main() {
  {
    Solution s;
    vector<vector<int>> routes {
      {1, 2, 7},
      {3, 6, 7},
    };
    int S = 1; int T = 1;
    int expected = 0;
    int ret = s.numBusesToDestination(routes, S, T);
    cout << "got " << ret << endl;
    assert(ret == expected);
  }
  {
    Solution s;
    vector<vector<int>> routes {
      {1, 2, 7},
      {3, 6, 7},
    };
    int S = 1; int T = 6;
    int expected = 2;
    int ret = s.numBusesToDestination(routes, S, T);
    cout << "got " << ret << endl;
    assert(ret == expected);
  }
  {
    Solution s;
    vector<vector<int>> routes {
      {1, 2, 3},
      {1, 4, 5},
    };
    int S = 1; int T = 5;
    int expected = 1;
    int ret = s.numBusesToDestination(routes, S, T);
    cout << "got " << ret << endl;
    assert(ret == expected);
  }
  {
    Solution s;
    vector<vector<int>> routes {
      {1, 2, 3},
      {6, 4, 5},
    };
    int S = 1; int T = 5;
    int expected = -1;
    int ret = s.numBusesToDestination(routes, S, T);
    cout << "got " << ret << endl;
    assert(ret == expected);
  }
  {
    Solution s;
    vector<vector<int>> routes {
      {1, 2, 3},
      {3, 4, 5},
      {5, 6, 7},
      {2, 7},
    };
    int S = 1; int T = 7;
    int expected = 2;
    int ret = s.numBusesToDestination(routes, S, T);
    cout << "got " << ret << endl;
    assert(ret == expected);
  }
  return 0;
}
>>>>>>> 2cb9d65 (Update 815.cpp)
=======
        if (S == T) return 0;
        hm_t<int, v_t<int>> rl;
        for (int i = 0; i < routes.size(); ++i) {
          for (int j = 0; j < routes[i].size(); ++j) {
            rl[routes[i][j]].push_back(i);
          }
        }
          
        deque<int> q;
        unordered_set<int> visited;
        
        int dis = 0;
        q.push_back(S);
        while (q.size()) {
            dis++;
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                int bs = q.front(); q.pop_front();
                for (auto r : rl[bs]) {
                    if (visited.count(r)) {
                        continue;
                    }
                    
                    visited.insert(r);
                    for (auto nbs : routes[r]) {
                       if (nbs == T) return dis;
                       q.push_back(nbs);
                    }
                }
                
            }
        }
        
        return -1;
    }
};
>>>>>>> ca578b0 (Update 815.cpp)
