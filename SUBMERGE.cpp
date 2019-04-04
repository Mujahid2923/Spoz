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
#define        zero(a)             memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


int node,edge,tim=0;
vi adj[10005];
int visited[10005];
int d[10005];
int low[10005];
int parent[10005];
int ap[10005];

void FindArticulationPoint(int u)
{
    d[u]=low[u]=++tim;
    visited[u]=1;
    int child=0;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(visited[v]==0)
        {
            child++;
            parent[v]=u;
            FindArticulationPoint(v);
            low[u]=min(low[u],low[v]);

            if(parent[u]==-1 && child>1)
            {
                ap[u]=1;
            }
            else if(parent[u]!=-1 && d[u]<=low[v])
            {
                ap[u]=1;
            }
        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],d[v]);
        }
    }
}

int main()
{
    int a,b;
    while(cin>>node>>edge)
    {
        if(node==0 && edge==0)
        {
            break;
        }
        zero(visited);
        zero(ap);

        for(int i=1; i<=edge; i++)
        {
            scin2(a,b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        for(int i=1; i<=node; i++)
        {
            parent[i]=-1;
        }

        for(int i=1; i<=node; i++)
        {
            if(visited[i]==0)
            {
                FindArticulationPoint(i);
            }
        }
        int cnt=0;
        for(int i=1; i<=node; i++)
        {
            if(ap[i]==1)
            {
                cnt++;
            }
        }
        pf("%d\n",cnt);

        for(int i=1; i<=node; i++)
        {
            adj[i].clear();
        }

    }
    return 0;
}


