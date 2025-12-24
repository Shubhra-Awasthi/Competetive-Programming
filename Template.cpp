// My custom template @Owl_

#include <bits/stdc++.h>
using namespace std;

// --------------------------- SPEED & TYPES ---------------------------
#define speeed                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define i128 __int128

// --------------------------- LOOP MACROS ---------------------------
#define FR(i, n) for (int i = 0; i < n; i++)
#define FR1(i, n) for (int i = 1; i < n; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, n) for (int i = (n) - 1; i >= 0; i--)
#define EACH(x, a) for (auto &x : a)

// --------------------------- CONSTANTS ---------------------------
#define mod 1000000007
#define mod2 998244353
#define INF 1000000000000000000LL

// --------------------------- STL SHORTCUTS ---------------------------
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((int)(x).size())

// --------------------------- CONTAINERS ---------------------------
#define pi pair<int, int>
#define vpi vector<pi>
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define si set<int>
#define usi unordered_set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define pqmax priority_queue<int>
#define pqmin priority_queue<int, vector<int>, greater<int>>

// ll versions
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<long long>
#define sll set<ll>
#define usll unordered_set<ll>
#define mll map<ll, ll>
#define umll unordered_map<ll, ll>
#define pqmaxll priority_queue<ll>
#define pqminll priority_queue<ll, vector<ll>, greater<ll>>

// --------------------------- FUNCTIONS ---------------------------
#define gcd __gcd
#define lcm(a, b) ((a) * (b)) / gcd((a), (b))
#define yes cout << "YES\n"
#define no cout << "NO\n"

// --------------------------- UTILITY TEMPLATES ---------------------------
struct pairHash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        uint64_t h1 = splitmix64(hash<T1>{}(p.first));
        uint64_t h2 = splitmix64(hash<T2>{}(p.second));
        return h1 ^ (h2 << 1);
    }
};

// --------------------------- MATH SHORTCUTS ---------------------------
#define bitcount(x) __builtin_popcountll(x)
#define lsb(x) __builtin_ctzll(x)
#define msb(x) (63 - __builtin_clzll(x))

// --------------------------- RANDOM ---------------------------
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand_int(a, b) uniform_int_distribution<int>(a, b)(rng)

void solve()
{
    //
}

int main()
{
    speeed;

    int T;
    cin >> T;
    // T = 1;

    while (T--)
    {
        solve();
    }
    return 0;
}
