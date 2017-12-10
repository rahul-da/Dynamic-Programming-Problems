//Trie implementation in C++
//Assuming alphabets a...z only
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
#define vll vector < long long int >
#define sll set < long long int >
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
/* //Topcoder blog implementation
string empty="";
struct trie
{
	int words;
	int prefixes;
	bool edges[26];
};
void initialize(trie vertex)
{
	vertex.words = 0;
	vertex.prefixes = 0;
	for(int i=0;i<26;i++)
		vertex.edges[i]=false;
}
void addWord(trie vertex,string word)
{
	if(word==empty)
		vertex.words = vertex.words + 1;
	else
	{
		vertex.prefixes = vertex.prefixes + 1;
		k = word[0];
		if(!vertex.edges[k])
		{
			vertex.edges[k] = true;
			
		}
	}
}
int countWords(trie vertex,string word)
{

}
int countPrefixes(trie vertex,string prefix)
{

}
int main()
{
	fastIO;
}
*/

//Trie Problem http://codeforces.com/contest/842/problem/D
//XOR Maximisation Problem
struct trienode
{
	char val;			   //Value of the node ('0' or '1')
	trienode *address[2];  //Pointer to its children (Max 2)
	bool isend;
};
string convert_to_string(int p)
{
	string s;

	ll i=p,q=0,j;
	fo(j,30)s.pb('0');

	while(i>0)
	{
		if(i%2==1)
			s[q++]='1';
		else 
			s[q++]='0';
		i/=2;
	}
	fo(j,15)
		swap(s[j],s[29-j]);
	return(s);
}
trienode* create_new_node()
{
	trienode *p =new trienode();
	p->address[0]=NULL;
	p->address[1]=NULL;
	p->isend = false;
	return(p);
}
void add_to_trie(trienode *root,ll p)
{
	ll i,j,k,l;
	string s = convert_to_string(p);
	trienode *node = root;

	fo(i,30)
	{
		if(node->address[s[i]-'0']==NULL)
			node->address[s[i]-'0'] = create_new_node();
		node=node->address[s[i]-'0'];
	}
	node->isend=true;
}
int find_min(trienode *root,ll x)
{
	ll i,j,k,l;
	string s = convert_to_string(x);
	string final;
	trienode *node=root;
	ll ans=0,mul=1;

	fo(i,30)
	{
		if(node->address[s[i]-'0']==NULL)
		{
			if(s[i]=='1')
			{
				final.pb('1');
				if(node->isend==true)break;
				node = node->address['0'-'0'];
			}
			if(s[i]=='0')
			{
				final.pb('1');
				if(node->isend==true)break;
				node = node->address['1'-'0'];
			}
		}
		else
		{
			final.pb('0');
			if(node->isend==true)break;
			node = node->address[s[i]-'0'];
		}
	}

	for(i=final.size()-1;i>=0;--i)
	{
		ans += (final[i]-'0')*mul;
		mul*=2;
	}
	return(ans);
}
int main()
{
	fastIO;
	ll n,m,i,j,k,a[300001],x=0,mex=-1,pqp;
	trienode *root = create_new_node();
	set < int > st;
	set < int >::iterator it;

	cin>>n>>m;
	fo(i,n)cin>>a[i],st.insert(a[i]);

	pqp=pow(2,19);
	fo(i,pqp)
	{
		if(st.find(i)!=st.end());
		else
		{
			// cout<<i<<endl;
			if(mex==-1)mex=i;
			add_to_trie(root,i);
		}
	}
	

	while(m--)
	{
		cin>>k;
		x=x^k;

		cout<<(find_min(root,x))<<endl;
	}
}