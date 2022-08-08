
#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef bool                      boo;
typedef int                       li;
typedef long long int             ll;
typedef unsigned long long int    l1;
typedef double                    db;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef vector < li >                   vli;
typedef vector < ll >                   vll;
typedef set < li >                      sli;
typedef set < ll >                      sll;
typedef pair < li, li >                 pli;
typedef pair < li, pair<li, li> >       pll;
typedef map < li,li >                   mli;
typedef map < ll,ll >                   mll;
typedef vector < pair < li, li > >      vpi;
typedef vector < pair < ll, ll > >      vpl;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define tc                        int t;cin>>t;while(t--)
#define inp_i(a,n)                for(i=0; i<n ;i++) cin>>a[i]
#define out_i(a, b, c)            for(i=b; i<c; i++) cout<<a[i] spc; cout nl;
#define lp(i,a,b)                 for(i=a;i<b;i++)
#define len(z)                    z.begin(),z.end()
#define faster                    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define input_txt                 freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define nl                        <<"\n"
#define spc                       <<" "
#define sp                        <<" "<<
#define co(x)                     cout<<x nl
#define sz(a)                     a.size()
#define cy                        cout<<"YES" nl
#define cn                        cout<<"NO" nl
#define pb                        push_back
#define F                         first
#define S                         second
#define pi                        2*acos(0.0)
#define clr(z)                    z.clear()
#define rn                        return
#define gcd(a,b)                  __gcd(a,b)
#define mem(b,z)                  memset(b,z,sizeof(b))
#define fixed(x)                  fixed<<setprecision(x)

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const ll lx = 2e5 + 9;
const ll mod = 998244353;
const ll LL_INF = (1LL << 62);

ll pre[lx];
map<pll, ll>mp;

bool check(ll x, ll y, ll z)
{
    ll a[3] = {x, y, z};
    sort(a, a+3);

    pll p;
    p.F = a[0];
    p.S.F = a[1];
    p.S.S = a[2];

    if(mp[p]) return true;
    mp[p]++;
    return false;
}

void pre_cal()
{
	for(int i = 1; i < lx; i++)
		pre[i] = pre[i-1]+i;
	for(int i = 1; i < lx; i++)
		pre[i] += pre[i-1];
	//co(pre[lx-1]);
}

ll sum(ll x)
{
    return x*(x-1)/2;
}

void solve()
{
    pre_cal();
    ll n, i, k, j, l, ans = 0, p;
    cin >> n >> k;
    vector<ll>v;
    map<ll, ll>m;

    for(i = 0; i < n; i++)
    {
        cin >> p;
        if(k%p == 0 and m[p] == 0)
        {
            v.push_back(p);
        }
        m[p]++;
    }
    sort(len(v));
    ll x, y, z, s;

    for(i = 0; i < v.size(); i++)
    {
        x = v[i];
        if(x*x*x == k and m[x] >= 3)
        {
            ans += pre[m[x]-2];
        }
        for(j = i+1; j < v.size(); j++)
        {
            y = v[j];
            z = k/(x*y);

            if(x*y*z != k or check(x, y, z)) continue;

            if(x == z)
            {
                s = sum(m[x])*m[y];
            }
            else if(y == z)
            {
                s = sum(m[y])*m[x];
            }
            else
            {
                s = m[x]*m[y]*m[z];
            }
           // co(x sp y sp z sp s);
            ans += s;
        }
    }
    cout << ans << "\n";
}

void init_code()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{
    faster

    solve();

}
