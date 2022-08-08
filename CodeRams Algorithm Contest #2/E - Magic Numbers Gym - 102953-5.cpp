
///              B I S M I L L A H I R  R A H M A N I R  R A H I M

// ============================================================================ //
// ||                                                                        || //
// ||             International University of Business Agriculture           || //
// ||                    and Technology, Dhaka, Bangladesh                   || //
// ||                           Emrul Hasan Emon                             || //
// ||                                                                        || //
// ============================================================================ //

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
typedef pair < li, li >                pli;
typedef pair < ll, li >                pll;
typedef map < li,li >                  mli;
typedef map < ll,ll >                  mll;
typedef vector < pair < li, li > >     vpi;
typedef vector < pair < ll, ll > >     vpl;

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

const ll lx = 1e7+7;
const ll mod = 998244353;

int length(ll n)
{
	int len = 0;
	while(n > 0)
	{
		len++;
		n /= 10;
	}
	return len;
}

ll check(ll x)
{
	string s;
	while(x > 0)
	{
		s += (char)(x%10 + '0');
		x /= 10;
	}

	reverse(len(s));

	int n = 0, m = 0, len = s.size();

	for(int i = 0; i < len/2; i++)
		n = 10*n + (s[i]-'0');

	for(int i = len/2; i < len; i++)
		m = 10*m + (s[i]-'0');

	if(n == m) return n;
	return -1;
}

bool hoise(ll n)
{
	int nine = 0, len = 0;
	while(n > 0)
	{
		len++;
		if(n%10 == 9) nine++;
		n /= 10;
	}
	if(nine == len) return true;
	return false;
}

ll answer(ll n, int len)
{
	ll m = 0;
	while(len--)
	{
		m = 10*m+9;
	}
	return m-n;
}
void solve()
{
	ll n;
	cin >> n;
	ll i, step = 0, j = 10;

    for(ll i = n; ; )
    {
    	int len = length(i);
    //	co(i sp len);

    	if(len%2 == 1)
    	{
    		if(hoise(i))
    			break;

    		step += answer(i, len);
    		break;
    		i++;
    		step++;
    	}
    	else
    	{
    		ll _n = check(i);
    		if(_n == -1) i++;
    		else i = _n;

    		step++;
    	}
    }

    cout << step << "\n";
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

// A L H A M D U L I L L A H
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 2 3 4 5....
// Emrul Hasan Emon
}
