//! Shwetank00
//! start
#include <bits/stdc++.h>
using namespace std;

//! shortcuts

#define getunique(v)                     \
    {                                    \
        sort(al(v));                     \
        v.erase(unique(al(v)), v.end()); \
    } //  remove duplicates and sort in ascending
#define input(a, n)             \
    for (int i = 0; i < n; i++) \
    cin >> a[i] //  take vector 'a' as input
#define print(a)           \
    for (auto it : a)      \
    {                      \
        cout << it << " "; \
    }                      \
    cout << endl //  print vector 'a'

#define deb1(x) cout << #x << "=" << x << endl                                                         // debugging
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl                             // debugging
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl // debugging
#define ll long long                                                                                   //  ll=long long
#define pb push_back                                                                                   //  push_back
#define F first                                                                                        //  first
#define S second                                                                                       //  second
#define sll set<long long>                                                                             //  set of long long
#define msll multiset<long long>                                                                       //  multiset of long long
#define mll map<ll, ll>                                                                                //  initialize map of long long,long long
#define mmll multimap<ll, ll>                                                                          //  initialize multimap
#define uset unordered_set<ll>                                                                         //  initialize unordered_set
#define lb lower_bound                                                                                 //  lb=lower_bound it is used to find the minimum element not less than a given value
#define ub upper_bound                                                                                 //  ub=upper_bound it is used to find the minimum element greater than a given value
#define Inf 1e18                                                                                       //  very large number
#define YES cout << "YES" << endl;                                                                     //  print 'YES' and a next line
#define NO cout << "NO" << endl;                                                                       //  print 'NO' and a next line
#define yes cout << "YES" << endl;                                                                     //  print 'YES' and a next line
#define no cout << "NO" << endl;                                                                       //  print 'NO' and a next line
#define nl_ cout << endl;                                                                              //  print a new line
#define clr(x) memset(x, 0, sizeof(x))                                                                 //  clear the whole array
#define dsort(x) sort(x.begin(), x.end(), greater<ll>());                                              //  sort vector 'x' in descending order
#define asort(x) sort(x.begin(), x.end())                                                              //  sort vector 'x' in ascending order
#define sortall(x) sort(all(x))                                                                        //  sort the whole thing
#define all(x) x.begin(), x.end()                                                                      //  first pointer to the last pointer
#define PI 3.1415926535897932384626                                                                    //  value of 'pi'
#define fo(i, n) for (i = 0; i < n; i++)                                                               //  loop i from 0 to n
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)                        //  loop i in from k to n
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)                                       //  iterate in 'a' and elements of a are 'it'
#define al(a) a.begin(), a.end()                                                                       //  iterate from left
#define alg(a) a.rbegin(), a.rend()                                                                    //  iterate from right
#define inmap(x, mymap) mymap.find(x) != mymap.end()                                                   //  find 'x' in mymap

//! initializing
typedef pair<int, int> pii; //  initialize a pair of int,int
typedef vector<int> vi;     //  initialize a vector of int
typedef vector<pii> vpii;   //  initialize a vector of pair of int,int
typedef vector<vi> vvi;     //  initialize a vector of vector of int
typedef pair<ll, ll> pl;    //  initialize a pair of ll,ll
typedef vector<ll> vl;      //  initialize a vector of ll
typedef vector<pl> vpl;     //  initialize a vector of pair of ll,ll
typedef vector<vl> vvl;     //  initialize a vector of vector of ll

//! bits
#define setbits(a) (__builtin_popcountll(a)) // to count 1 bits
#define right(a) (__builtin_ctzll(a))        // to count trailing 0s
#define left(a) (__builtin_clzll(a))         // to count leading 0s
#define parity(a) (__builtin_parityll(a))    // to check even odd

//! funcion initializations
ll modInverse(ll A, ll M);
int mpow(int base, int exp);
ll GCD(ll a, ll b);
ll nCr(ll n, ll r, ll M);
bool isPrime(ll n);
void prnt(vector<ll> a);
void prnt(vector<vector<ll>> a);
void prnt(vector<pair<ll, ll>> a);

//! defining constants
const int mod = 1000000007; // 1e9+7

//! function definitions

void prnt(vector<ll> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " \n"[i == a.size() - 1];
    }
}

//? ----------------------------------------------------------------------------------------------------
void prnt(vector<vector<ll>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " \n"[j == a[i].size() - 1];
        }
    }
}

//? ----------------------------------------------------------------------------------------------------
void prnt(vector<pair<ll, ll>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i].F << " \n"[i == a.size() - 1];
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i].S << " \n"[i == a.size() - 1];
    }
}

//? ----------------------------------------------------------------------------------------------------
ll GCD(ll a, ll b)
{
    while ((a > 0) && (b > 0))
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        return b;
    return a;
}

//? ----------------------------------------------------------------------------------------------------
ll nCr(ll n, ll r, ll M)
{
    if (r > n)
        return 0ll;
    if (r == n || r == 0)
        return 1ll;
    ll a1 = 1, a2 = 1, a3 = 1, i;
    for (i = 1; i <= n; i++)
        a1 = (a1 * i) % M;
    for (i = 1; i <= r; i++)
        a2 = (a2 * i) % M;
    for (i = 1; i <= n - r; i++)
        a3 = (a3 * i) % M;
    a2 = (a2 * (a3)) % M;
    a2 = modInverse(a2, M);
    a1 = (a1 * a2) % M;
    return a1;
}

//? ----------------------------------------------------------------------------------------------------
int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

//? ----------------------------------------------------------------------------------------------------
ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;
    if (M == 1)
        return 0;
    while (A > 1)
    {
        int q = A / M;
        int t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

//? ----------------------------------------------------------------------------------------------------

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

//! Shwetank00.cpp
//! function to solve the question
void Devil()
{
}

//! Main function
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        Devil();
    }
    return 0;
}
