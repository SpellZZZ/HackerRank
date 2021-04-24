#include <iostream>

using namespace std;

int main()
{
    int n,k;

    int wynik=0;

    cin>>n>>k;

    int tab[n];

    for (int i=0;i<n;i++)
        cin>>tab[i];


    for(int i=0;i<n;i++)
    {
         for(int j=i+1;j<n;j++)
         {
             if((tab[i]+tab[j])%k == 0)wynik++;
         }
    }

    cout<<wynik;
    return 0;
}
