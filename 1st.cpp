#include <iostream>
#include <vector>
#include <deque>
using namespace std;

bool isGood(const vector<int>& q) {
    int n = q.size();
    if (n < 5) return true;
    for (int i = 0; i <= n - 5; i++) {
        if ((q[i] < q[i+1] && q[i+1] < q[i+2] && q[i+2] < q[i+3] && q[i+3] < q[i+4]) ||
            (q[i] > q[i+1] && q[i+1] > q[i+2] && q[i+2] > q[i+3] && q[i+3] > q[i+4])) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter size of array: ";
        cin >> n;
        vector<int> p(n);
        cout << "Enter elements of array: ";
        for (int i = 0; i < n; i++) cin >> p[i];

        int l = 0, r = n - 1;
        vector<int> q;
        string answer = "";

        while (l <= r) {
            // Try taking from left
            q.push_back(p[l]);
            if (isGood(q)) {
                answer += 'R';
                l++;
            } else {
                q.pop_back();
                // Try taking from right
                q.push_back(p[r]);
                answer += 'L';
                r--;
            }
        }

        cout << answer << endl;
    }

    return 0;
}
