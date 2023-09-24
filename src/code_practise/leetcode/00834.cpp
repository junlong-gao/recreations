class Solution {
    vector<vector<int>> g;
    vector<int> count, distChild, dist;
    int tot;
    int countNodes(int r, int p) {
        count[r] = 1;
        for (int n : g[r]) {
            if (n == p) {
                continue;
            }
            count[r] += countNodes(n, r);
        }
        return count[r];
    }
    
    int countChildDist(int r, int p) {
        for (int n : g[r]) {
            if (n == p) {
                continue;
            }
            distChild[r] += countChildDist(n, r) + count[n];
        }
        return distChild[r];
    }
    
    void compute(int r, int p, int inSum) {
        dist[r] += inSum;
        for (int n : g[r]) {
            if (n == p) {
                continue;
            }
            dist[r] += distChild[n] + count[n];
        }
        
        for (int n : g[r]) {
            if (n == p) {
                continue;
            }
            compute(n, r, tot - count[n] + (dist[r] - (distChild[n] + count[n])));
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        g.resize(n);
        count.resize(n, 0);
        distChild.resize(n, 0);
        dist.resize(n, 0);
        tot = n;
        
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        assert(n == countNodes(0, -1));
        countChildDist(0, -1);
        
        compute(0, -1, 0);
        return dist;
    }
};