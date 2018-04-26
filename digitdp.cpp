#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define pii pair < int , int >
#define vi vector < int >
#define pb push_back
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
#define vll vector < long long int >
#define sll set < long long int >
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
ll dp[20][2][10];
vector < ll > dig(ll x)
{
    vector < ll > v;
    v.clear();
    while(x>0)v.pb(x%10),x/=10;
    reverse(v.begin(),v.end());
    return(v);
}
ll fun(vector < ll > digit,ll idx, ll tight, ll sum)
{
    ll i,j,k,cons,val=0;
    if(idx==0)
    {
        if(sum!=0)return 1ll;
        else return 0ll;
    }
    if(dp[idx][tight][sum]!=-1)return(dp[idx][tight][sum]);
    if(tight==1)cons=min(8ll,digit[digit.size()-idx]);
    else cons=8ll;
    fo(i,cons)
    {
        val += fun(digit,idx-1,0,(sum+i)%9);
    }
    if(cons==digit[digit.size()-idx] and tight==1)val += fun(digit,idx-1,1,(sum+cons)%9);
    else val += fun(digit,idx-1,0,(sum+cons)%9);
    if(tight==0)
    {
        dp[idx][tight][sum] = val;
    }
    return(val);
}
int main()
{
    fastIO;
    ll t,f,l,pp=0ll;
    cin>>t;
    while(t--)
    {
        ll i,j,k;
        fo(i,20)fo(j,2)fo(k,10)dp[i][j][k]=-1ll;
        cin>>f>>l;
        vector < ll > v;
        v = dig(l);
        cout<<"Case #"<<(++pp)<<": ";
        cout<<fun(dig(l),dig(l).size(),1,0)-fun(dig(f-1),dig(f-1).size(),1,0)<<" "<<endl;
    }
}