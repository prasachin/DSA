#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vvll vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define mii map<int, int>
#define mis map<int, string>
#define msi map<string, int>
#define si set<int>
#define sll set<long long>
#define sc set<char>
/* FUNCTIONS */
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
/* PRINTS */
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << "," << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os;
    string sep;
    for (const T &x : v)
        os << sep << x, sep = " ";
    return os;
}
/* UTILS */
#define M 1000000007
string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
bool chk_pali(string s)
{
    for (int i = 0; i < (int)s.length() / 2; i++)
        if (s[i] != s[s.length() - 1 - i])
            return 0;
    return 1;
}
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
#define all(a) (a).begin(), (a).end()

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);          // columns   |
        vector<bool> diag1(2 * n - 1, false); // main diagonal
        vector<bool> diag2(2 * n - 1, false);
        backtrack(solutions, board, cols, diag1, diag2, 0, n);
        return solutions;
    }

private:
    void backtrack(vector<vector<string>> &solutions, vector<string> &board, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2, int row, int n)
    {
        if (row == n)
        {
            solutions.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
            {
                continue;
            }
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
            backtrack(solutions, board, cols, diag1, diag2, row + 1, n);
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    Solution solution;
    vector<vector<string>> results = solution.solveNQueens(n);
    for (const auto &solution : results)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << endl;
    }
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
}
