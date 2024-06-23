#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define all(a) (a).begin(), (a).end()

void solve() // prefer binary search solution for this problem with better time complexity !
{
    int n, k;
    cin >> n >> k;
    vector<int> books(n);
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }

    // dp[i][j] means the minimum of the maximum pages that can be allocated to i students from the first j books
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));

    vector<int> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + books[i - 1];
    }

    // Base case: with one student, they take all books
    for (int j = 1; j <= n; j++)
    {
        dp[1][j] = prefix_sum[j];
    }

    for (int i = 2; i <= k; i++)
    { // for each student count
        for (int j = 1; j <= n; j++)
        { // for each book count
            for (int p = 0; p < j; p++)
            { // partition point
                dp[i][j] = min(dp[i][j], max(dp[i - 1][p], prefix_sum[j] - prefix_sum[p]));
            }
        }
    }

    cout << dp[k][n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
