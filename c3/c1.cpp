#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > input()
{
    int numDays, numSettlements, tempLim;
    cin >> numSettlements >> numDays >> tempLim;
    vector<vector<int >> data(numSettlements);
    for (int m = 0; m < numSettlements; ++m)
    {
        for (int n = 0; n < numDays; ++n)
        {
            int x;
            cin >> x;
            data[m].push_back(x);
        }
    }
    return data;
}

int processData(vector<vector<int> > data)
{
    long numSettlements = data.size();
    long numDays = data[0].size();
    int hotDayCounter[numSettlements];
    for (int i = 0; i < numSettlements; i++)
    {
        hotDayCounter[i] = 0;
    }
    
    int maxTemp = -1;
    int maxTempIndex = -1;
    for (int n = 0; n < numDays; ++n)
    {
        for (int m = 0; m < numSettlements; ++m)
        {
            if (data[m][n] > maxTemp)
            {
                maxTemp = data[m][n];
                maxTempIndex = m;
            }
        }
        hotDayCounter[maxTempIndex]++;
    }

    int maxHotDays = -1;
    int maxIndex = -1;
    for (int i = 0; i < numSettlements; ++i)
    {
        if (hotDayCounter[i] > maxHotDays)
        {
            maxHotDays = hotDayCounter[i];
            maxIndex = i;
        }
    }
    return maxIndex + 1;
}

void Start()
{
    cout << processData(input());
}

int main(int argc, char const *argv[])
{
    Start();
    return 0;
}
