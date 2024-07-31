#include <bits/stdc++.h>
using namespace std;

double multiply(double num, int n) {
    double ans = 1.0;
    for (int i = 0; i < n; i++) {
        ans *= num;
    }
    return ans;
}

int nroot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while ((high - low) > eps) {
        double mid = (high + low) / 2.0;
        if (multiply(mid, n) < m) {
            low = mid;
        } else {
            high = mid;
        }
    }

    // Since we are looking for an integer root, we check if the found value is an integer.
    int root = round(low); // rounding to nearest integer
    if (multiply(root, n) == m) {
        return root;
    } else {
        return -1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int result = nroot(n, m);
    cout << result << endl;
    return 0;
}
