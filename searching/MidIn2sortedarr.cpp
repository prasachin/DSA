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

void solve()
{
    ll n1, n2;
    cin >> n1 >> n2;
    vll u, v;
    for (int i = 0; i < n1; i++)
    {
        int k;
        cin >> k;
        u.push_back(k);
    }

    for (int i = 0; i < n2; i++)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }

    int begin = 0, end = n1;
    while (begin <= end)
    {
        int i1 = (begin + end) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;
        int min1 = (i1 == n1) ? INT_MAX : u[i1];
        int max1 = (i1 == 0) ? INT_MIN : u[i1 - 1];

        int min2 = (i2 == n2) ? INT_MAX : v[i2];
        int max2 = (i2 == 0) ? INT_MIN : v[i2 - 1];

        if (max2 <= min1 && max1 <= min2)
        {
            if ((n1 + n2) % 2 == 0)
            {
                cout << (double)(max(max1, max2) + min(min1, min2)) / 2 << endl;
                break;
            }
            else
            {
                cout << (double)(max(max1, max2)) << endl;
                break;
            }
        }
        else if (max1 > min2)
        {
            end = i1 - 1;
        }
        else
        {
            begin = i1 + 1;
        }
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