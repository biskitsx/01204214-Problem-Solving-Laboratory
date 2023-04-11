#include <iostream>
#include <vector>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    while(test_cases--) {
        int items_count, price, weight, group_size, max_weight, ans = 0;
        vector<int> dp(31);
        cin >> items_count;
        for(int i = 0; i < items_count; i++) {
            cin >> price >> weight;
            for(int j = 30; j >= weight; j--) {
                if(dp[j] < dp[j - weight] + price) {
                    dp[j] = dp[j - weight] + price;
                }
            }
        }
        cin >> group_size;
        for(int i = 0; i < group_size; i++) {
            cin >> max_weight;
            ans += dp[max_weight];
        }
        cout << ans << endl;
    }
    return 0;
}
