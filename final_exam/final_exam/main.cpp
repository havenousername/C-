
#include <iostream>
#include <vector>
using namespace std;
struct Meat
{
    string meatType;
    int butcherID;
};
bool isUnique(int id, int i, vector<Meat> meats)
{
    int j = 1;
    while ((j < meats.size() && meats[j].butcherID != id) || (j == i))
    {
        j++;
    }
    return j == meats.size();
};
int main()
{
    int numberOfButchers;
    cin >> numberOfButchers;
    int numberOfPairs;
    cin >> numberOfPairs;
    vector<Meat> Pairs(numberOfPairs + 1);
    for (int i = 1; i <= numberOfPairs; i++)
    {
        cin >> Pairs[i].meatType >> Pairs[i].butcherID;
    }
    //first subtask
    cout << "#" << endl;
    int cnt = 0;
    vector<string> MeatTypes;
    for (int i = 1; i <= numberOfPairs; i++)
    {
        MeatTypes.push_back(Pairs[i].meatType);
    }
    for (int i = 1; i <= MeatTypes.size(); i++)
    {
        int j = 0;
        for (j = 0; j < i; j++)
            if (MeatTypes[i] == MeatTypes[j])
                break;
        if (i == j)
            cnt++;
    }
    cout << cnt << endl;
    //second subtask
    cout << "#" << endl;
    //    vector<Meat> counting;
    string unique_meat = "NONE";

    for (int i = 1; i <= Pairs.size(); i++)
    {
        if (isUnique(Pairs[i].butcherID, i, Pairs))
        {
            cerr << Pairs[i].meatType;
            unique_meat = Pairs[i].meatType;
            break;
        }
    }
    cout << unique_meat;
    return 0;
}
