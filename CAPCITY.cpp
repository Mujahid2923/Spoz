///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define       zero(a)              memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

int node,edge;
vi adj[100005];
vi radj[100005];
vi result[100005];
int visited[100005];
int color[100005];
stack<int>st;
vi vec;

void dfs(int u)
{
    color[u]=1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(color[v]==0)
            dfs(v);
    }
    st.push(u);
}

void ssc(int u,int mark)
{
    result[mark].pb(u);
    visited[u]=1;
    for(int i=0; i<radj[u].size(); i++)
    {
        int v=radj[u][i];
        if(visited[v]==0)
            ssc(v,mark);
    }
}

int main()
{
    int a,b;
    scin2(node,edge);
    for(int i=0; i<edge; i++)
    {
        scin2(a,b);
        adj[a].pb(b);
        radj[b].pb(a);
    }

    for(int i=1; i<=node; i++)
    {
        if(color[i]==0)
        {
            dfs(i);
        }
    }

    int mark=0;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(visited[u]==0)
        {
            ssc(u,mark);
            mark++;
        }
    }
    for(int i=0; i<mark; i++)
    {
        if(result[i].size()>1)
        {
            for(int j=0; j<result[i].size(); j++)
            {
                vec.pb(result[i][j]);
            }
        }
    }
    sort(vec.begin(),vec.end());
    cout<<vec.size()<<endl;
    for(auto i : vec)
        cout<<i<<" ";
    return 0;
}

