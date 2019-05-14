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


///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

vl v, vec ;
ll t , n , m , temp ;

ll BinSearch( ll low , ll high )
{
    ll mid, result = 0 ;
    while( low <= high )
    {
        mid = ( low + high ) / 2 ;
        ll sum = 0, cnt = 1 ;
        for( int i = 0 ; i < v.size() ; i++ )
        {
            sum += v[ i ] ;
            if( sum >= mid )
            {
                sum = 0 ;
                cnt ++ ;
            }
        }

        if( cnt >= m )
        {
            result = mid ;
            low = mid + 1 ;
        }
        else if( cnt < m )
        {
            high = mid - 1 ;
        }
    }

    return result ;
}

int main()
{
    cin >> t ;
    while( t-- )
    {
        scln2( n, m ) ;
        for( int i = 0 ; i < n ; i++ )
        {
            scln( temp ) ;
            vec.pb( temp ) ;
        }

        sort( vec.begin(), vec.end() ) ;
        ll mn = INT_MAX ;
        for( int i = 0 ; i < n - 1 ; i++ )
        {
            temp = vec[ i + 1 ] - vec[ i ] ;
            mn = min( mn, temp ) ;
            v.pb( temp ) ;
        }
        if( n == m )
        {
            cout << mn << endl ;
        }
        else
        {
            ll x = BinSearch( 1 , 1000000001 ) ;
            cout << x << endl ;
        }
        vec.clear() ;
        v.clear() ;
    }

    return 0;
}

------------------Another Approach---------------------
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


///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

vl v, vec ;
ll t, n, m, temp ;

ll BinSearch( ll low, ll high )
{
    ll mid , result = 0 ;
    while( low <= high )
    {
        mid = ( low + high ) / 2 ;
        ll cnt = 1 , bit = vec[ 0 ];
        for( int i = 1 ; i < vec.size() ; i++ )
        {
             if( vec[ i ] - bit >= mid )
             {
                 cnt++ ;
                 bit = vec[ i ] ;
             }
        }

        if( cnt >= m )
        {
            result = mid ;
            low = mid + 1 ;
        }
        else if( cnt < m )
        {
            high = mid - 1 ;
        }
    }

    return result ;
}

int main()
{
    cin >> t ;
    while( t-- )
    {
        scln2( n, m ) ;
        for( int i = 0 ; i < n ; i++ )
        {
            scln( temp ) ;
            vec.pb( temp ) ;
        }

        sort( vec.begin(), vec.end() ) ;

        ll x = BinSearch( 1 , 1000000001 ) ;
        cout << x << endl ;
        vec.clear() ;
        v.clear() ;
    }

    return 0;
}



