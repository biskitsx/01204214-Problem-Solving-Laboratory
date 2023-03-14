#include<iostream>
#include<vector>
#define MAX_N 100001
using namespace std ;

struct inch {
    int start, stop, weight;
};

int n;
vector<inch> Intervals(MAX_N); 
int dp[MAX_N];
int maxIdx = 0; // variable to keep track of the index of the maximum weight
vector<int> res;

void readInput() {
    int s, t, w;
    cin >> n;
    for (int i = 0; i < n ; i++) {
        cin >> s >> t >> w;
        Intervals[i].start = s;
        Intervals[i].stop = t;
        Intervals[i].weight = w;
    }
}

int main() {
    readInput(); 
    dp[0] = Intervals[0].weight;

    for (int i = 1; i < n; i++) {
        dp[i] = Intervals[i].weight;

        for (int j = i - 1; j >= 0; j--) {
            if (Intervals[j].stop <= Intervals[i].start) {
                if (dp[i] < dp[j] + Intervals[i].weight) {
                    dp[i] = dp[j] + Intervals[i].weight;
                    maxIdx = i; // update max weight index
                    break; 
                }
            }
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n-1] << endl;

    int currIdx = maxIdx;
    while (currIdx >= 0) {
        res.push_back(currIdx);
        int prevIdx = -1;
        for (int j = currIdx - 1; j >= 0; j--) {
            if (Intervals[j].stop <= Intervals[currIdx].start && dp[currIdx] == dp[j] + Intervals[currIdx].weight) {
                prevIdx = j;
                break;
            }
        }
        currIdx = prevIdx;
    }
    cout << res.size() <<endl; 
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i]+1 << " ";
    }

    return 0;
}
