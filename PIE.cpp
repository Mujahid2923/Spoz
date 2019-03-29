#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)
int n;

double volume(double vol[],double mid)
{
    int num=0;
    for(int i=0; i<n; i++)
    {
        num=num+vol[i]/mid;
    }
    return num;
}


double searchvalue(double vol[],int f)
{
    double low=0;
    double high=vol[n-1];
    double mid;
    while(high-low>0.00001)
    {
        mid=(low+high)/2;
        if(volume(vol,mid)<f)
        {
            high=mid;
        }
        else
        {
            low=mid;
        }
    }
    return mid;
}

int main()
{
    int t,f;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>n>>f;
        int arr[n];
        double vol[n];
        for(int j=0; j<n; j++)
        {
            cin>>arr[j];
            vol[j]=arr[j]*arr[j]*pi;
        }
        sort(vol,vol+n);

        double ans=searchvalue(vol,f+1);
        printf("%.4lf\n",ans);

    }
    return 0;
}
