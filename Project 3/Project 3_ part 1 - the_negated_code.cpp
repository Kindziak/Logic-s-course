#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char ** argv)
{
    int Arg[6]; //arguments' array

    if (argc >= 7) //load arguments from the command line
    {
        for(int i=0;i<6;i++)
        {
            Arg[i]=atoi(argv[i+1]);
        }
    }
    else //or load arguments by the user
    {
        cout << "Nie podales szesciu liczb. Podaj je teraz: ";
        for(int i=0;i<6;i++)
        {
            cin >> Arg[i];
        }
    }
    
    if (( Arg[0] <= 0 || Arg[1] != Arg [5] ) && (( Arg[2]%Arg[3]!=0 && Arg[3]<=Arg[2] ) ||  Arg[4]==0 ))
    {
        cout<< 1;
    }
    else
    {
        cout<< 0;
    }

    return 0;
}
