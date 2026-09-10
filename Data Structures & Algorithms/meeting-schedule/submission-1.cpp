/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.end < b.end;
        });
        Interval curr = intervals[0];

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start < curr.end) {
                return false;
            } else {
                curr = intervals[i];
            }
        }
        return true;
    }
};
