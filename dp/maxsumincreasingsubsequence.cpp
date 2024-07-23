#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n) {
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
    }

    int maxSum = 0;
    for (int value:dp) {
        maxSum = max(maxSum, value);
    }

    return maxSum;
}

int main() {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The maximum sum of increasing subsequence is " << maxSumIS(arr, n) << endl;

    return 0;
}
