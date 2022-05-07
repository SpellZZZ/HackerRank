#include <bits/stdc++.h>

using namespace std;


template <typename T>
  std::string NumberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }



  int StringToNumber ( string str , int o)
  {
        int num;
        std::stringstream ss;
        ss << str[o];
        ss >> num;
     return num;
  }

  void Check(vector<int> &tab, int index)
  {
      if(tab[index]  % 10 == 0 )
      {
          int o = tab[index]  / 10;

          tab[index]= 0;
          tab[index+1]+=o;
      }
      else if (tab[index]  > 10 )
      {
          int o = tab[index]  / 10;
          tab[index+1]+=o;
          tab[index]= tab[index]%10;

      }

  }




int main()
{


    vector<int>podstawa;
    vector<int>mnozona;
    vector<int>wynik(200, 0);

    int n;
    int d;
    cin >> n;


    int a = 1;
    //int b = 12;

    string st = NumberToString(a);

    for(int i =st.size()-1;i>-1;i--)
    {
        podstawa.push_back(StringToNumber(st,i));  //rev podstawa
    }



for(int p=2;p<=n;p++)
{


    string nd = NumberToString(p);



    for(int i =nd.size()-1;i>-1;i--)
    {
        mnozona.push_back(StringToNumber(nd,i));  //rev mnozona
    }


    d=0;


    for(int i =0;i<mnozona.size();i++)
    {
        for(int j =i;j<i+podstawa.size();j++)
        {
            wynik[j] += podstawa[d]*mnozona[i];
            d++;
             Check(wynik, j);
        }
        d=0;
    }
    podstawa = wynik;


    for(int i =0;i<wynik.size();i++)
    {
        wynik[i]=0;
    }
    mnozona.clear();

    }


        int z = -1;
    for(int i = podstawa.size()-1;i>-1;i--)
        {
            if(podstawa[i]==0 && z == -1)
            {
                continue;
            }
            else
            {
                cout<<podstawa[i];
                z = 2;
            }
        }



    return 0;
}












