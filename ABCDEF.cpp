#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];

    int RHS[n*n*n+1];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int index=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i])
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    RHS[index++]=arr[i]*(arr[j]+arr[k]);
                }
            }
        }
    }
    sort(RHS,RHS+index);


    int result=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                int x=(arr[i]*arr[j])+arr[k];
                result += (upper_bound(RHS,RHS+index,x)-lower_bound(RHS,RHS+index,x));

            }
        }
    }
    cout<<result<<endl;
    return 0;
}

