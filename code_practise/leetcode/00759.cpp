/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
    vector<Interval> intersect(const vector<Interval>& l, const vector<Interval> &r) {
        vector<Interval> ret;
        int i = 0, j = 0;
        while (i < l.size() && j < r.size()) {
            const Interval& li = l[i];
            const Interval& ri = r[j];
            
            if (l[i].end <= r[j].start || r[j].end <= l[i].start) {
                // no intersection
            } else {
                ret.push_back(Interval{max(l[i].start, r[j].start), min(l[i].end, r[j].end)});
                
            }
            
            if (l[i].end > r[j].end) {
                j++;
            } else {
                i++;
            }
        }
        return ret;
    }
    
    vector<Interval> compliment(const vector<Interval>& in) {
        int curStart = INT_MIN;
        vector<Interval> ret;
        for (int i = 0; i < in.size(); ++i) {
            if (curStart < in[i].start) {
                ret.emplace_back(Interval{curStart, in[i].start});
            }
            curStart = in[i].end;
        }
        
        if (curStart < INT_MAX) {
            ret.emplace_back(Interval{curStart, INT_MAX});
        }
        
        return ret;
    }
    
    vector<Interval> uni(const vector<Interval> &l, const vector<Interval> &r) {
        vector<Interval> ret;
        int i = 0, j = 0;
        while (i < l.size() && j < r.size()) {
            if (l[i].end < r[j].start || r[j].end < l[i].start) {
                if (l[i].start < r[j].start) {
                    ret.push_back(l[i]);
                } else {
                    ret.push_back(r[j]);
                }
            } else {
                ret.push_back(Interval{min(l[i].start, r[j].start), max(l[i].end, r[j].end)});
            }
            
            if (l[i].end > r[j].end) {
                j++;
            } else {
                i++;
            }
        }
        while (i < l.size()) {
            ret.push_back(l[i]);
            i++;
        }
        while (j < r.size()) {
            ret.push_back(r[j]);
            j++;
        }
        return ret;
    }
    
    // assert(compliment(uni(l, r)) == intersect(compliment(l), compliment(r)));
public:
    vector<Interval> employeeFreeTime2(vector<vector<Interval>> schedule) {
        vector<Interval> ret;
        
        ret.emplace_back(Interval{INT_MIN, INT_MAX});
        
        for (int i = 0; i < schedule.size(); ++i) {
            vector<Interval> free = compliment(schedule[i]);
            auto tmp = intersect(ret, free);
            
            swap(ret, tmp);
        }
        
        if (ret.empty()) {
            return ret;
        }
        
        if (ret[0].start == INT_MIN) {
            ret.erase(ret.begin());
        }
        if (ret.back().end == INT_MAX) {
            ret.pop_back();
        }
        
        return ret;
    }
    
    vector<Interval> employeeFreeTime3(vector<vector<Interval>> schedule) {
        vector<Interval> ret;
        
        for (int i = 0; i < schedule.size(); ++i) {
            auto tmp = uni(ret, schedule[i]);
            
            swap(ret, tmp);
        }
        
        auto tmp = compliment(ret);
        swap(ret, tmp);
        
        if (ret.empty()) {
            return ret;
        }
        
        if (ret[0].start == INT_MIN) {
            ret.erase(ret.begin());
        }
        if (ret.back().end == INT_MAX) {
            ret.pop_back();
        }
        
        return ret;
    }
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> flatten, ret;
        
        for (auto &s : schedule) {
            for (auto &i : s) {
                flatten.push_back(i);
            }
        }
        sort(flatten.begin(), flatten.end(), [](const Interval &l, const Interval &r) {
            return l.start < r.start;
        });
        
        if (flatten.empty()) {
            return {};
        }
        int cur = flatten[0].end;
        for (int i = 0; i < flatten.size(); ++i) {
            if (cur < flatten[i].start) {
                ret.emplace_back(Interval{cur, flatten[i].start});
            }
            cur = max(cur, flatten[i].end);
        }
        return ret;
    }
};
