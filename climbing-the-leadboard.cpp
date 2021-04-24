#include <iostream>
#include <vector>

using namespace std;

class dane
{
    public:
        int liczbaOsob;
        int turyGracza;
        vector<int>wynikiOsob;
        vector<int>wynikiGracza;
        vector<int>miejsceGraczaTab;


};



void wprowadzDane(dane &tab)
{

    cin>>tab.liczbaOsob;
    int pomocnicza;
    int pomocnicza2 = 1;

    for(int i=0;i<tab.liczbaOsob;i++)
    {
        cin>>pomocnicza;
        if(i==0)tab.wynikiOsob.push_back(pomocnicza);
        else if(i!=0 && pomocnicza!=tab.wynikiOsob[pomocnicza2-1])
        {
            pomocnicza2++;
            tab.wynikiOsob.push_back(pomocnicza);
        }

    }



    tab.liczbaOsob = tab.wynikiOsob.size();


    cin>>tab.turyGracza;
    for(int i=0;i<tab.turyGracza;i++)
    {
        cin>>pomocnicza;
        tab.wynikiGracza.push_back(pomocnicza);
    }
}




void miejsceGracza(dane &tab)
{
    int pomoc = tab.liczbaOsob-1;

    int miejsce = 0;
    for(int i=0;i<tab.turyGracza;i++)
    {
    miejsce = 1;

    for(int j=pomoc;j>0;j--)
    {

        if(pomoc>0 && tab.wynikiGracza[i]>=tab.wynikiOsob[j])
        {
            pomoc--;
        }
        else
            break;


    }

    if(pomoc==-1)miejsce=1;
    else if(tab.wynikiGracza[i]==tab.wynikiOsob[pomoc])miejsce= pomoc+1;
    else if(tab.wynikiGracza[i]<tab.wynikiOsob[pomoc])miejsce= pomoc+2;

    tab.miejsceGraczaTab.push_back(miejsce);
    }


}







int main()
{
    dane tab;

    wprowadzDane(tab);
    miejsceGracza(tab);


    for(int i=0;i<tab.turyGracza;i++)
    {
        cout<<tab.miejsceGraczaTab[i]<<endl;
    }





    return 0;
}
