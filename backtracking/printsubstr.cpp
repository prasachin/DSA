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

bool isSafe(string s, int l, int i, int r, const string &forbidden)
{
    if (l != 0 && s.substr(max(0, l - (int)forbidden.size() + 1), forbidden.size()) == forbidden)
    {
        return false;
    }
    if (i != l && s.substr(max(0, i - (int)forbidden.size() + 1), forbidden.size()) == forbidden)
    {
        return false;
    }
    return true;
}

void getPermutations(string s, int l, int r, const string &forbidden, unordered_set<string> &result)
{
    if (l == r)
    {
        if (s.find(forbidden) == string::npos)
        {
            result.insert(s);
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            if (isSafe(s, l, i, r, forbidden))
            {
                swap(s[l], s[i]);
                getPermutations(s, l + 1, r, forbidden, result);
                swap(s[l], s[i]);
            }
        }
    }
}

void solve()
{
    cout << "Enter the string: " << endl;
    string s;
    cin >> s;
    string r;
    cout << "Enter the substring to be avoided: " << endl;
    cin >> r;
    int n = s.size();
    unordered_set<string> result;
    getPermutations(s, 0, n - 1, r, result);
    for (const string &perm : result)
    {
        cout << perm << endl;
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
    return 0;
}
