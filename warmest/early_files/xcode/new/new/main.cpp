#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct Meat
{
    string meatType;
    int butcherID;

};

bool isUniqueMeat(vector<Meat> m, string meat, int i)
{
    int j = 0;
    while ((j < m.size() && m[j].meatType != meat) || j == i)
    {
        j++;
    }
    return (j == m.size());
};

int main()
{
    int numberOfButchers;
    cin>>numberOfButchers;
    int numberOfPairs;
    cin>>numberOfPairs;
    vector<Meat>Pairs(numberOfPairs);
    for (int i=0; i<numberOfPairs; i++)
    {
        cin>>Pairs[i].meatType>>Pairs[i].butcherID;
    }
    //first subtask
    cout<<"#"<<endl;
    int cnt=0;
    vector<string>MeatTypes;
    for (int i=0; i<numberOfPairs; i++)
    {
        MeatTypes.push_back(Pairs[i].meatType);
    }
    for (int i=1; i<=MeatTypes.size(); i++)
    {
        int j=0;
        for (j=0; j<i; j++)
            if (MeatTypes[i] == MeatTypes[j])
            break;
        if (i==j)
            cnt++;
    }
    cout<<cnt<<endl;
    // second subtask
    cout << "#" << endl;
    string unique_meat = "NONE";
    for (int i = 0; i < numberOfPairs; i++)
    {
        if(isUniqueMeat(Pairs, Pairs[i].meatType, i)){
            unique_meat = Pairs[i].meatType;
            break;
        }
    }

    int i = 0;
    while (i < numberOfPairs && !isUniqueMeat(Pairs, Pairs[i].meatType, i)){
        i++;
    }
    unique_meat = Pairs[i].meatType;
    cout<< unique_meat << endl;
    // third task
    cout << "#" << endl;
    set<string> s;
    vector<Meat> count_meat;
    // copy into set
    for (int i = 0; i < Pairs.size(); i++)
    {
        s.insert(Pairs[i].meatType);
    }

    set<string>::iterator it;

    // find counts
    for (it = s.begin(); it != s.end(); ++it)
    {
        int j = 0;
        Meat meat = {*it, 0};
        count_meat.push_back(meat);
        int count = 0;
        while (j < numberOfPairs)
        {
            if (Pairs[j].meatType == meat.meatType)
            {
                count_meat.back() = {*it, ++count};
            }
            j++;
        }
    }

    for(auto c : count_meat){
        cout << c.meatType << " " << c.butcherID << endl;
    }

    // fourth task
    cout << "#" << endl;
    int butcherest_butcher = Pairs[0].butcherID;
    int butcherest_meat = 0;
    for (int i = 0; i < numberOfPairs; i++)
    {
        int j = i+1;
        int count = 0;
        while (j < numberOfPairs)
        {
            if (Pairs[i].butcherID == Pairs[j].butcherID && Pairs[i].meatType != Pairs[j].meatType)
            {
                count++;
                cerr << "Something" << endl;
            }
            j++;
        }
        if(count > butcherest_meat){
            butcherest_meat = count;
            butcherest_butcher = Pairs[i].butcherID;
        }
    }
    cout << butcherest_butcher << endl;
    return 0;
}

