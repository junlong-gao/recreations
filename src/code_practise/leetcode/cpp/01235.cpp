class Solution {
    struct ent_t {
        int s, e, p;
    };
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       vector<ent_t> jobs;
        for (int i = 0; i < startTime.size(); ++i) {
            jobs.emplace_back(ent_t{startTime[i], endTime[i], profit[i]});
        }
        auto cmp = [](const ent_t &l, const ent_t &r) {
            return l.e < r.e;
        };
        sort(jobs.begin(), jobs.end(), cmp);
        vector<int> dp(jobs.size());
        for (int i = 0; i < jobs.size(); ++i) {
            if (i == 0) {
                dp[i] = jobs[i].p;
            } else {
                dp[i] = dp[i-1];
                auto fake = jobs[i];
                fake.e = fake.s;
                auto it = upper_bound(jobs.begin(), jobs.begin() + i, fake, cmp);
                if (it == jobs.begin()) {
                    dp[i] = max(dp[i], jobs[i].p);
                } else {
                    dp[i] = max(dp[i], jobs[i].p + dp[it - jobs.begin() - 1]);
                }
            }
        }
        return dp.back();
    }
};