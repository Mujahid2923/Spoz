#include<bits/stdc++.h>
using namespace std;

#define ll  long long int

ll binarySearch(ll arr[],ll n,ll k)
{
    ll low=1;
    ll high=arr[n-1];
    ll ans=0;

    while(low<=high)
    {
        ll mid=(low+high)/2;
        ll cal=0;
        for(ll i=0; i<n; i++)
        {
            if(arr[i]==0)
            {
                continue;
            }
            cal=cal+(arr[i]/mid);
        }

        if(cal==k)
        {
            ans=mid;
            low=mid+1;
        }

        else if(cal>k)
        {
            low=mid+1;
            ans=mid;
        }
        else if(cal<k)
        {
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    ll t,n,k;
    scanf("%lld",&t);
    for(ll i=0; i<t; i++)
    {
        scanf("%lld %lld",&n,&k);
        ll arr[n];
        for(ll j=0; j<n; j++)
        {
            scanf("%lld",&arr[j]);
        }
        sort(arr,arr+n);
        ll ans=binarySearch(arr,n,k);
        printf("%lld\n",ans);
    }
    return 0;
}

/*

3
3 2
3 1 4
4 1
3 2 3 9
2 3
3 3

Ans: 3 9 1
*/

