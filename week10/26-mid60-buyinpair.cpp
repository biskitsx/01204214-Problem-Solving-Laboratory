#include <iostream>
#include <vector>

using namespace std;

vector<int> prices;
int n, a, b;
bool seen[1000001];

void readInput() {
    cin >> n >> a >> b;
    prices.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
}

int count_two_sum_prices() {
    int countt = 0;

    for (int i = 0; i < n; i++) {
        for (int target = a - prices[i] + 1; target < b - prices[i]; target++) {
            if (target >= 0 && target <= 1000000 && seen[target]) {
                countt++;
            }
        }
        seen[prices[i]] = true;
    }

    return countt;
}

int main() {
    readInput();
    cout << count_two_sum_prices() << endl;
    return 0;
}
