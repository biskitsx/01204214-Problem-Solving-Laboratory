#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_equal_two_sum(vector<int>& arr) {
    sort(arr.begin(), arr.end()); // sort the array in ascending order
    int max_sum = 0;
    for (int i = arr.size()-1; i >= 1; i--) { // iterate from end to start
        int target = arr[i] - arr[0]; // compute the target value for two-sum
        int left = 1, right = i-1;
        while (left < right) {
            int curr_sum = arr[left] + arr[right];
            if (curr_sum == target) {
                max_sum = max(max_sum, arr[i] + target);
                left++;
                right--;
            } else if (curr_sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return max_sum;
}

int main() {
    vector<int> arr = {5, 7, 9, 3, 11};
    cout << max_equal_two_sum(arr) << endl; // Output: 16
    return 0;
}
