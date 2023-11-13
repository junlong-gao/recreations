class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> versions;
        vector<string> res;
        for (auto &r : names) {
            if (versions.count(r) == 0) {
                res.push_back(r);
                versions[r] = 1;
            } else {
                int idx = versions[r];
                while (versions.count(r+"("+to_string(idx)+")") > 0) {
                    idx++;
                }
                versions[r]=idx;
                string v = r+"("+to_string(idx)+")"; 
                versions[v] =1;
                res.push_back(v);
            }
        }
        return res;
    }
};