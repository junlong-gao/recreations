class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int lv, rv, uh, dh;
        {
            int lo = -1, hi = y;
            while (lo + 1 < hi) {
                int mid = lo + (hi - lo) / 2;
                int pi = 0;
                for (int i = 0; i < image.size(); ++i) {
                    pi += image[i][mid] - '0';
                }
                if (pi == 0) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            
            lv = hi;
        }
        {
            int lo = y - 1, hi = image[0].size();
            while (lo + 1 < hi) {
                int mid = lo + (hi - lo) / 2;
                int pi = 0;
                if (mid != image[0].size()) {
                    for (int i = 0; i < image.size(); ++i) {
                        pi += image[i][mid] - '0';
                    }
                }
                if (pi > 0) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            
            rv = hi;
        }
        {
            int lo = -1, hi = x;
            while (lo + 1 < hi) {
                int mid = lo + (hi - lo) / 2;
                int pi = 0;
                for (int i = 0; i < image[mid].size(); ++i) {
                    pi += image[mid][i] - '0';
                }
                if (pi == 0) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            
            uh = hi;
        }
        {
            int lo = x-1, hi = image.size();
            while (lo + 1 < hi) {
                int mid = lo + (hi - lo) / 2;
                int pi = 0;
                if (mid != image.size()) {
                    for (int i = 0; i < image[mid].size(); ++i) {
                        pi += image[mid][i] - '0';
                    }
                }
                if (pi > 0) {
                    lo = mid; 
                } else {
                    hi = mid;
                }
            }
            dh = hi;
        }
        return (dh - uh) * (rv - lv);
    }
};