class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int, int> line;
        int ret = 0;
        int wIdx = 0;
        for (int i = 0; i < rows; ++i) {
            if (line.count(wIdx) == 0) {
                int &ans = line[wIdx];
                int spaceUsed = 0;
                while (true) {
                    int space = (ans > 0 ? 1 : 0);
                    if (spaceUsed + sentence[wIdx].size() + space > cols) {
                        break;
                    }
                    spaceUsed += sentence[wIdx].size() + space;
                    wIdx = (wIdx + 1) % sentence.size();
                    ans++;
                }
                ret += ans;
            } else {
                ret += line[wIdx];
                wIdx = (wIdx + line[wIdx]) % sentence.size();
            }
        }
        return ret / sentence.size();
    }
};
