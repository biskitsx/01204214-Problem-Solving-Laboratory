#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int left ;
    int right;
};

bool compareIntervals(const Interval &i1, const Interval &i2) {
    return i1.left < i2.left;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int targetLength;
        cin >> targetLength;

        vector<Interval> intervals(1);
        while (cin >> intervals[0].left >> intervals[0].right, !(intervals[0].left == 0 && intervals[0].right == 0)) {
            intervals.push_back(intervals[0]);
        }

        sort(intervals.begin() + 1, intervals.end(), compareIntervals);

        size_t i = 1;
        vector<Interval> selectedIntervals;
        int curLeft = 0 ;
        int rightmost = 0;

        while (rightmost < targetLength) {
            int newLeft = curLeft;
            size_t farthest = 0;
            for (; i < intervals.size(); ++i) {
                if (intervals[i].left > curLeft) {
                    break;
                } else if (intervals[i].right >= newLeft) {
                    newLeft = intervals[i].right;
                    farthest = i;
                }
            }
            if (farthest == 0) {
                break;
            }
            selectedIntervals.push_back(intervals[farthest]);
            curLeft = rightmost = newLeft;
        }
        if (rightmost >= targetLength) {
            cout << selectedIntervals.size() << endl;
            for (size_t i = 0; i < selectedIntervals.size(); ++i) {
                cout << selectedIntervals[i].left << " " << selectedIntervals[i].right << endl;
            }
        } else {
            cout << "0" << endl;
        }
        if (testCases) {
            cout << endl;
        }
    }

    return 0;
}
