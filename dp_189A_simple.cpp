#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define pii pair < int , int >
#define vi vector < int >
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
const ll mod = 1e9+7;
using namespace std;
ll n,a,b,c,dp[4001],vis[4001];
ll fun(ll x)
{
    if(vis[x]==1)return(dp[x]);
    if(x==0)return(0);
    if(x<0)return(-1 * mod);
    ll s=0;
    s = max(fun(x-a)+1,fun(x-b)+1);
    s = max(s,fun(x-c)+1);
    vis[x]=1;
    dp[x]=s;
    return(dp[x]);

}
int main()
{
    fo(i,4001)
    {
        dp[i]=0;
        vis[i]=0;
    }
    cin>>n>>a>>b>>c;
    if(a>b)swap(a,b);
    if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    cout<<fun(n);
}
