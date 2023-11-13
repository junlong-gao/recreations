class Solution {
    /*
This has nothing to do with union find/dfs

Consider input:
[1, 1, 2]

1. One may be tempted to use dfs, but this requires building a graph
   where x -> y iff y = x + 1
   but such a graph can have at most O(n^2) edges: [x, x, ... , x+1, x+1, ...]
   
2. Also union find does not work either: when unioning with a seen set, how
   can you know the set has already got that element you are looking at?
   [1, 2, 1]
   When looking at the last 1, there is no way to know {1,2} already has 1
   
A straightforward solution in fact works in O(n):
Since input is not sorted, we can assume it has the following layout:
[0, 1, 2, 3, 4, 5, 7, 8]  => [0, 1, 1, 2, 2, 3, 4, 4, 4, 5, 7, 7, 8]
    1  2     4     7          ^                             ^                                
             4 
repetition does not matter. For every element seen, if it is a beginning
of a run, we just need to scan until we reach the end of the run. For n
elements, it is hence partitioned as above into "runs", and for each
run we loop at most the run length, so the total number of elements we
check is O(n)
    */
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lk;
        for (auto e : nums) {
            lk.insert(e);
        }
        
        int ret = 0;
        for (auto e : nums) {
            if (lk.count(e - 1)) {
                continue;
            }
            // we only care about beginning of a run
            int k = e; int m = e;
            while (lk.count(e)) {
                e++;
            }
            
            ret = max(ret, e - k);
        }
        
        return ret;
    }
};
