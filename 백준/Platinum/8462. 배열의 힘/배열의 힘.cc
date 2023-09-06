#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int DAT[1000001] = { 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n>>m;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<pair<pair<int, int>, int>> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    int sq = sqrt(n);
    sort(queries.begin(), queries.end(), [sq](const auto& a, const auto& b) {
        int block_a = a.first.first / sq;
        int block_b = b.first.first / sq;
        if (block_a != block_b) {
            return block_a < block_b;
        }
        return a.first.second < b.first.second;
        });

    long long cnt = 0;
    int lp = queries[0].first.first - 1;
    int rp = queries[0].first.second - 1;
    //cout << lp << " " << rp << endl;
    for (int i = lp; i <= rp; ++i) {
        cnt += arr[i] * (2*DAT[arr[i]] + 1);
        DAT[arr[i]]++;
    }

    vector<long long> result(m);
    result[queries[0].second] = cnt;

    for (int i = 1; i < m; ++i) {
        int l = queries[i].first.first - 1;
        int r = queries[i].first.second - 1;

        while (lp < l) {
            cnt -= arr[lp] * (2 * DAT[arr[lp]] - 1);
            DAT[arr[lp]]--;
            lp++;
        }

        while (lp > l) {
            lp--;
            cnt += arr[lp] * (2 * DAT[arr[lp]] + 1);
            DAT[arr[lp]]++;
        }

        while (rp < r) {
            rp++;
            cnt += arr[rp] * (2 * DAT[arr[rp]] + 1);
            DAT[arr[rp]]++;
        }

        while (rp > r) {
            cnt -= arr[rp] * (2 * DAT[arr[rp]] - 1);
            DAT[arr[rp]]--;
            rp--;
        }
        result[queries[i].second] = cnt;
    }

    for (int i = 0; i < m; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}