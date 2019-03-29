#include <iostream>
using namespace std;

int main() {
	int t,n,x;
    cin>>t;
    short int arr[160];
    while(t--)
    {
        arr[0]=1;
        cin>>n;
        int m=1;
        int temp=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<m; j++)
            {
                x=arr[j]*i+temp;
                arr[j]=x%10;
                temp=x/10;
            }
            while(temp!=0)
            {
                arr[m]=temp%10;
                temp=temp/10;
                m++;
            }
        }
        for(int i=m-1; i>=0; i--)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }
	return 0;
}
