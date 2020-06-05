#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct BankNote
{
    string country;
    string color;
    int value;
};
int main()
{
    int BankNotesNumber;
    cin>>BankNotesNumber;
    vector<BankNote>BankNotes(BankNotesNumber);
    for (int i=0; i<BankNotesNumber; i++)
    {
        cin>>BankNotes[i].country>>BankNotes[i].color>>BankNotes[i].value;
    }
    cout<<"#"<<endl;
    int minValue=BankNotes[0].value;
    string minCountry=BankNotes[0].country;
    string minColor=BankNotes[0].color;
    for (int i=1; i<BankNotesNumber; i++)
    {
        if (BankNotes[i].value < minValue)
        {
            minValue=BankNotes[i].value;
            minCountry=BankNotes[i].country;
            minColor=BankNotes[i].color;
        }
    }
    cout<<minColor<<" "<<minCountry<<endl;
    cout<<"#"<<endl;
    cout<<"#"<<endl;
    set<string> colors;
    // putting in set
    for (int i = 0; i < BankNotes.size(); i++)
    {
        colors.insert(BankNotes[i].color);
    }

    set<string>::iterator it;
    cout << colors.size() << endl;
    for (it = colors.begin(); it != colors.end(); ++it){
        cout << *it << endl;
    }

    cout << "#" << endl;
    string lotsOfColorsCountry = BankNotes[0].country;
    int lotsOfColors = 0;
    for (int i = 0; i < BankNotesNumber; i++)
    {
        int j = i+1;
        int countColors = 0;
        while (j < BankNotesNumber)
        {
            if(BankNotes[i].color == BankNotes[j].color){
                countColors++;
            }
            j++;
        }
        if (countColors > lotsOfColors)
        {
            lotsOfColorsCountry = BankNotes[i].country;
            lotsOfColors = countColors;
        }
    }
    cout << lotsOfColorsCountry << endl;
    cout<<"#"<<endl;


    return 0;
}
