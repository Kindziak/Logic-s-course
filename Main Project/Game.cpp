#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

char CalculationNot(int argc,char ** argv,char first)
{
    string fileName=argv[1];
    ifstream file;
    file.open(fileName.c_str());
    if(!file.good()) return '4';
    char dane[4];
    for (int i=0;i<3;i++) dane[i]=' ';
    for(int i=0;i<4;i++)
    {
        file.getline(dane,4);
        if(first==dane[0])return dane[2];
    }
    return '5';
}

char CalculationAnd(int argc, char ** argv,char first,char second)
{
    string fileName=argv[2];
    ifstream file;
    file.open(fileName.c_str());
    if(!file.good()) return '4';
    char dane[6];
    for(int i=0;i<6;i++) dane[i]=' ';
    for(int i=0;i<9;i++)
    {
        file.getline(dane,6);
        if(first==dane[0]&&second==dane[2])return dane[4];
    }
    return '5';
}

char CalculationOr(int argc, char ** argv,char first,char second)
{
    string fileName=argv[3];
    ifstream file;
    file.open(fileName.c_str());
    if(!file.good()) return '4';
    char dane[6];
    for (int i=0;i<6;i++) dane[i]=' ';
    for(int i=0;i<9;i++)
    {
        file.getline(dane,6);
        if(first==dane[0]&&second==dane[2])return dane[4];
    }
    return '5';
}

char CalculationImpl(int argc, char ** argv,char first,char second)
{
    string fileName=argv[4];
    ifstream file;
    file.open(fileName.c_str());
    if(!file.good()) return '4';
    char dane[6];
    for (int i=0;i<6;i++) dane[i]=' ';
    for(int i=0;i<9;i++)
    {
        file.getline(dane,6);
        if(first==dane[0]&&second==dane[2])return dane[4];
    }
    return '5';
}

int Puzzle1(int argc, char ** argv)
{
    cout<< "Mariusz lubi spac, a jego kolega Artur nie. \n";
    cout<< "Zona jednego z nich ma przeciwne upodobania, a druga nie wie czy lubi spac. \n";
    cout<< "Czy prawda jest, ze ktoras z par zgadza sie w tej kwesti? \n";
    cout<< "1. TAK \n";
    cout<< "2. NIE \n";
    cout<< "3. NIE WIADOMO \n";

    // solution

    char l='1'; //lubi spac
    char n='0'; //nie lubi spac
    char w='X'; //nie wiemy cyz lubi spac
    int goodAnswer=0;
    char answer=CalculationOr(argc,argv,CalculationOr(argc,argv,CalculationAnd(argc,argv,l,n),CalculationAnd(argc,argv,l,w)),CalculationOr(argc,argv,CalculationAnd(argc,argv,n,l),CalculationAnd(argc,argv,n,w)));

    switch(answer)
    {
    case '1':
        goodAnswer=1;
        break;
    case '0':
        goodAnswer=2;
        break;
    case 'X':
        goodAnswer=3;
        break;
    case '4':
        goodAnswer=4;
        break;
    }
    return goodAnswer;
}

int Puzzle2(int argc, char ** argv)
{
    cout<< "Kasia jedzie w gory.\n";
    cout<< "Kasia chce zabrac jeszcze swoja kolezanke Anie, ktora sie ciagle zastanawia. \n";
    cout<< "Chlopak Ani nigdzie nie jedzie i chce, zeby zostala. \n";
    cout<< "Czy mozemy powiedziec, ze jezeli Kasia nie pojedzie w gory to Ania dalej bedzie niezdecydowana albo, ze \n";
    cout<< "gdy jej chlopak pojedzie to Ania tez? \n";
    cout<< "1. TAK \n";
    cout<< "2. NIE \n";
    cout<< "3. NIE WIADOMO \n";

    // solution

    char k='1'; //Kasia jedzie w gory
    char a='X'; //Ania jest niezdecydowana
    char c='0'; //chlopak Ani zostaje
    int goodAnswer=0;
    char answer=CalculationOr(argc,argv,CalculationImpl(argc,argv,CalculationNot(argc,argv,k),a),CalculationImpl(argc,argv,CalculationNot(argc,argv,c),a));

    switch(answer)
    {
    case '1':
        goodAnswer=1;
        break;
    case '0':
        goodAnswer=2;
        break;
    case 'X':
        goodAnswer=3;
        break;
    case '4':
        goodAnswer=4;
        break;
    }
    return goodAnswer;
}

int Puzzle3(int argc, char ** argv)
{
    cout<< "Wiemy, ze wczoraj jest przeszloscia, a jutro jest niewiadoma. \n";
    cout<< "Czy prawda jest, ze jezeli jest wczoraj to bedzie jutro albo ze jesli jest jutro to bedzie wczoraj? \n";
    cout<< "1. TAK \n";
    cout<< "2. NIE \n";
    cout<< "3. NIE WIADOMO \n";

    // solution

    char d='X'; //jutro to niewiadoma
    char j='0'; //wczoraj to przeszlosc wiec juz go nie ma
    int goodAnswer=0;
    char answer=CalculationOr(argc,argv,CalculationImpl(argc,argv,d,j),CalculationImpl(argc,argv,j,d));

    switch(answer)
    {
    case '1':
        goodAnswer=1;
        break;
    case '0':
        goodAnswer=2;
        break;
    case 'X':
        goodAnswer=3;
        break;
    case '4':
        goodAnswer=4;
        break;
    }
    return goodAnswer;
}

int Puzzle4(int argc, char ** argv)
{
    cout<< "Jest takie powiedzenie: Po burzy zawsze wychodzi slonce. \n";
    cout<< "To stwierdzenie uznajemy za prawdziwe.\n";
    cout<< "Czy mozna powiedziec, ze jezeli nie ma slonca to nie bylo burzy? \n";
    cout<< "1. TAK \n";
    cout<< "2. NIE \n";
    cout<< "3. NIE WIADOMO \n";

    // solution

    char b='1'; //jest burza
    char s='1'; //jest slonce
    char ns=CalculationNot(argc,argv,s); //nie ma slonca
    char nb=CalculationNot(argc,argv,b); //nie ma burzy
    int goodAnswer=0;
    char answer=CalculationImpl(argc,argv,CalculationImpl(argc,argv,b,s),CalculationImpl(argc,argv,ns,nb));

    switch(answer)
    {
    case '1':
        goodAnswer=1;
        break;
    case '0':
        goodAnswer=2;
        break;
    case 'X':
        goodAnswer=3;
        break;
    case '4':
        goodAnswer=4;
        break;
    }
    return goodAnswer;
}

int Puzzle5(int argc, char ** argv)
{
    cout<< "W pewnym miescie zyja trzy rodzaje ludzi: prawdomowni, klamcy i normalni. \n" ;
    cout<< "Prawdomowni zawsze mowia prade, klamcy zawsze klamia, a normalni raz klamia raz mowia prawde. \n";
    cout<< "Spotyka sie trzech przyjaciol. Klamca mowi: \"Wsrod nas jest conajmniej dwoch klamcow\". \n";
    cout<< "Jego kolega odpowiada: \"Tak, a dokladniej trzech\". \n";
    cout<< "Czy mozliwe jest, zeby trzecia i druga osoba byly normalna ? \n";
    cout<< "1. TAK \n";
    cout<< "2. NIE \n";
    cout<< "3. NIE WIADOMO \n";

    // solution

    char k='0'; //klamstwo
    char p='1'; //wiemy, ze klamca sklamal,wiec jest jeden klamca co jest prawda
    char d='X'; //drugi jest niewiadomy, czyli tak jakby normalny lub niewiadoma
    char t='X'; //trzeci tak samo
    int goodAnswer=0;
    char answer=CalculationAnd(argc,argv,CalculationAnd(argc,argv,CalculationImpl(argc,argv,k,p),CalculationImpl(argc,argv,d,d)),t);

    switch(answer)
    {
    case '1':
        goodAnswer=3; //cos musi byc zle :P
        break;
    case '0':
        goodAnswer=2;
        break;
    case 'X':
        goodAnswer=1; //poniewaz wyszlo ze obaj moga byc normalni
        break;
    case '4':
        goodAnswer=4;
        break;
    }
    return goodAnswer;
}

int Puzzle6(int argc, char ** argv)
{
    cout<< "Jezeli zakladamy, ze nastepujace zadanie jest prawdziwe: \n";
    cout<< "\"Jesli Kinga moze glosowac, to ma wiecej niz 18 lat\", to czy to zdanie: \n";
    cout<< "\"Kinga moze glosowac albo nie ma ponad 18 lat\" i to zdanie: \n";
    cout<< "\"Jesli Kinga ma wiecej niz 18 lat, to nie moze glosowac\" sa prawdziwe? \n";
    cout<< "1. TAK \n";
    cout<< "2. NIE \n";
    cout<< "3. NIE WIADOMO \n";

     // solution

    char p='1'; //Kinga moze glosowac
    char q='1'; //Kinga ma wiecej niz 18 lat
    char np=CalculationNot(argc,argv,p);
    char nq=CalculationNot(argc,argv,q);
    int goodAnswer=0;
    char answer=CalculationAnd(argc,argv,CalculationOr(argc,argv,p,nq),CalculationImpl(argc,argv,q,np));

    switch(answer)
    {
    case '1':
        goodAnswer=1;
        break;
    case '0':
        goodAnswer=2;
        break;
    case 'X':
        goodAnswer=3;
        break;
    case '4':
        goodAnswer=4;
        break;
    }
    return goodAnswer;
}

int SelectionOfPuzzles(int argc, char ** argv,int & one,int & two,int & three)
{
    int goodAnswer;
    int PuzzleNumber=(rand()%6)+1;
    while(PuzzleNumber==one || PuzzleNumber==two || PuzzleNumber==three)
    {
        PuzzleNumber=(rand()%6)+1;
    }
    switch(PuzzleNumber)
    {
    case 1:
        if(one==0)one=PuzzleNumber;
        else
        {
            if(two==0)two=PuzzleNumber;
            else three=PuzzleNumber;
        }
        goodAnswer=Puzzle1(argc,argv);
        break;
    case 2:
        if(one==0)one=PuzzleNumber;
        else
        {
            if(two==0)two=PuzzleNumber;
            else three=PuzzleNumber;
        }
        goodAnswer=Puzzle2(argc,argv);
        break;
    case 3:
        if(one==0)one=PuzzleNumber;
        else
        {
            if(two==0)two=PuzzleNumber;
            else three=PuzzleNumber;
        }
        goodAnswer=Puzzle3(argc,argv);
        break;
    case 4:
        if(one==0)one=PuzzleNumber;
        else
        {
            if(two==0)two=PuzzleNumber;
            else three=PuzzleNumber;
        }
        goodAnswer=Puzzle4(argc,argv);
        break;
    case 5:
        if(one==0)one=PuzzleNumber;
        else
        {
            if(two==0)two=PuzzleNumber;
            else three=PuzzleNumber;
        }
        goodAnswer=Puzzle5(argc,argv);
        break;
    case 6:
        if(one==0)one=PuzzleNumber;
        else
        {
            if(two==0)two=PuzzleNumber;
            else three=PuzzleNumber;
        }
        goodAnswer=Puzzle6(argc,argv);
        break;
    }
    return goodAnswer;
}

void GiveHint()
{
    cout<< "W plikach, ktore podawales jako argumenty, jest zawarta logika trojwartosciowa. \n";
    cout<< "Kazdy wiersz to zdanie (pierwszy argument,drugi argument i wynik lub argument i wynik). \n";
    cout<< "Zagadke postaraj sie ulozyc w zdanie logiczne. :) \n";
}

void BombOrDiamond()
{
    cout<< "Na koncu drogi znajdujesz podejzana skrzynie,a w srodku ";
    int a=(rand()%2);
    if(a==0)
    {
        cout<< "BOMBA ! \n";
        cout<< "Nie zyjesz. \n";
        cout<< "        PRZEGRALES :( \n\n\n";
    }
    else
    {
        cout<< "OGROMNY DIAMENT :D \n";
        cout<< "Szczescie Ci sprzyja. \n";
        cout<< "        WYGRALES ! \n\n\n";
    }
}

// The main program

int main (int argc, char ** argv)
{
    srand(time(NULL));

    string Not,Impl,Or,And;
    char hint;
    int correctAnswer,playersAnswer,points=0,numberOfHints=1;
    bool flag=false;

    if(argc<5) cout<< "Nie podales plikow potrzebnych do gry. Wywolanie to: \nGra.exe not.txt and.txt or.txt impl.txt";

    // Game is starting

    cout<< "        Witamy w grze DROGA DO SKARBU \n";
    cout<< "Zasady sa proste. Idziesz sciezka i na kazdym rozstaju drog spotykasz medrca, ktory zadaje Ci zagadke. \n";
    cout<< "Zawsze sa trzy odpowiedzi: TAK, NIE, NIE WIADOMO. Podczas gry mozna skorzystac raz z podpowiedzi. \n";
    cout<< "Trzy dobre odpowiedzi to gora skarbow, dwie to skrzynia z bomba albo ogromnym diamentem, \n";
    cout<< "jedna to powrot do poczatku, a same zle odpowiedzi to smierc. :) Dopiero na koncu dowiesz sie co wygrales. \n";
    cout<< "        POWODZENIA! \n\n\n";

    while(flag==false)
    {
        int one,two,three;
        one=two=three=0;
        points=0;
        // First puzzle

        cout<< "Spotykasz pierwszego medrca, ktory zadaje ci zagadke: \n";
        correctAnswer=SelectionOfPuzzles(argc,argv,one,two,three);
        if(correctAnswer==4)
        {
            cout<< "Blad otwarcia pliku.";
            return 0;
        }
        if(correctAnswer==5)
        {
            cout<< "Blad pliku";
            return 0;
        }
        if(numberOfHints==1)
        {
            cout<< "\nPotrzebujesz podpowiedzi ? T/N ";
            cin>> hint;
            while(hint!='T' && hint!='N')
            {
                cout<< "\nZla litera. Podaj jeszce raz: ";
                cin>> hint;
            }
            if(hint=='T')
            {
                GiveHint();
                numberOfHints=0;
            }
        }
        cout<< "\nPodaj odpowiedz (1/2/3) : ";
        cin>> playersAnswer;
        while(playersAnswer!=1 && playersAnswer!=2 && playersAnswer!=3)
        {
                cout<< "\nZla cyfra. Podaj jeszce raz: ";
                cin>> playersAnswer;
        }
        if(playersAnswer==correctAnswer) points++;
        cout<< "\nIdziesz wybrana przez siebie sciezka...";

        // Second puzzle

        cout<< "Spotykasz kolejnego medrca, ktory zadaje ci zagadke: \n";
        correctAnswer=SelectionOfPuzzles(argc,argv,one,two,three);
        if(correctAnswer==4)
        {
            cout<< "Blad otwarcia pliku.";
            return 0;
        }
        if(correctAnswer==5)
        {
            cout<< "Blad pliku";
            return 0;
        }
        if(numberOfHints==1)
        {
            cout<< "\nPotrzebujesz podpowiedzi ? T/N ";
            cin>> hint;
            while(hint!='T' && hint!='N')
            {
                cout<< "\nZla litera. Podaj jeszce raz: ";
                cin>> hint;
            }
            if(hint=='T')
            {
                GiveHint();
                numberOfHints=0;
            }
        }
        cout<< "\nPodaj odpowiedz (1/2/3) : ";
        cin>> playersAnswer;
        while(playersAnswer!=1 && playersAnswer!=2 && playersAnswer!=3)
        {
                cout<< "\nZla cyfra. Podaj jeszce raz: ";
                cin>> playersAnswer;
        }
        if(playersAnswer==correctAnswer) points++;
        cout<< "\nIdziesz wybrana przez siebie sciezka...";

        // Third puzzle

        cout<< "Spotykasz ostatniego medrca, ktory zadaje ci zagadke: \n";
        correctAnswer=SelectionOfPuzzles(argc,argv,one,two,three);
        if(correctAnswer==4)
        {
            cout<< "Blad otwarcia pliku.";
            return 0;
        }
        if(correctAnswer==5)
        {
            cout<< "Blad pliku";
            return 0;
        }
        if(numberOfHints==1)
        {
            cout<< "\nPotrzebujesz podpowiedzi ? T/N ";
            cin>> hint;
            while(hint!='T' && hint!='N')
            {
                cout<< "\nZla litera. Podaj jeszce raz: ";
                cin>> hint;
            }
            if(hint=='T')
            {
                GiveHint();
                numberOfHints=0;
            }
        }
        cout<< "\nPodaj odpowiedz (1/2/3) : ";
        cin>> playersAnswer;
        while(playersAnswer!=1 && playersAnswer!=2 && playersAnswer!=3)
        {
                cout<< "\nZla cyfra. Podaj jeszce raz: ";
                cin>> playersAnswer;
        }
        if(playersAnswer==correctAnswer) points++;
        cout<< "\nDotarles do konca drogi. \n\n\n";

        // Finish

        cout<< "Tak o to odpowiedziales na trzy zagadki. Teraz dowiesz sie czy wygrales. :)\n";
        switch(points)
        {
            case 0:
                cout<< "        PRZEGRALES!!!\n";
                cout<< "Na koncu drogi zjada cie smok :(\n\n\n";
                flag=true;
                break;
            case 1:
                BombOrDiamond();
                flag=true;
                break;
            case 2:
                cout<< "Szedles w kolko musisz cala podroz przebyc jeszcze raz.\n";
                cout<< "        POWODZENIA!!!\n\n\n";
                break;
            case 3:
                cout<< "        WYGRALES!!!\n";
                cout<< "Na koncu drogi znajdujesz niekonczacy sie skarb ! :D \n\n\n";
                flag=true;
                break;
        }
    }
    cout<< "\n\n\n        KONIEC!!!\n\n\n";
    return 0;
}
