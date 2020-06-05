
// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits>

using namespace std;

template <class T>

T validate_input(const T low, const T high, const string& message, const string& error){
    T input = low - 1;
    while(input < low || input > high){
        cout << message;

        while((cin >> input).fail() || cin.peek() != '\n'){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << error;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}


int find_duplicate(vector<int> v)
{
    int i = 0;
    for (int j = 0; j < v.size(); j++)
    {
        i = 0;
        while ((i < v.size() && v[i] != v[j]) || i == j)
        {
            i++;
        }
        if (i < v.size())
        {
            break;
        }
    }
    return i;
};

int take_dup_index(vector<int> v, int d)
{
    int j = 0;
    while (j < v.size() && d != v[j])
    {
        j++;
    }
    if (j < v.size())
    {
        return j;
    }
    else
    {
        return 0;
    }
};

int give_biggest(vector<int> out)
{
    int biggest = 0;
    int cnt = 0;
    for (int i = 0; i < out.size(); i++)
    {
        if (out[i] > cnt)
        {
            biggest = i;
            cnt = out[i];
        }
    }
    return biggest;
};

bool hasNoDuplicates(vector<int> v, int limit, int i)
{
    int j = 0;
    while ((j < v.size() && i != v[j]) || j == limit)
    {
        j++;
    }
    return (j == v.size());
};

int main()
{

    int N = 0, M = 0, L = 0;
    cout << "====Continuosly warmest settlement====\n";
    cout << "Please write down settlements, days and temperature limit\n";
    cout << "Separate each input by new line\n";


    N = validate_input(1, 1000, "Settlement\n", "Error. Try again\n");
    M = validate_input(1, 1000, "Day\n", "Error. Try again\n");
    L = validate_input(20, 50, "Temperature limit\n", "Error. Try again\n");

    cout << "Next, write down in each column settlement's temperature:\n";
    vector<vector<int> > weather(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> weather[i][j];
        }
    }

    // First, transpose matrix in order to have simplify task
    vector<vector<int> > transpose(M);
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            transpose[j].push_back(weather[i][j]);
        }
    }

    // Initialize helper data collections
    vector<int> out(N);
    set<int> duplicates;

    // Main computation part
    if (N > 1)
    {   
        // looping over transpose matrix in order to find in each column maximum temperatures
        for (int i = 0; i < transpose.size(); i++)
        {
            int max = L;
            int index = 0;
            for (int j = 0; j < transpose[i].size(); j++)
            {
                // Take maximum temperature, which is unique (biggest temp can not have duplicates) 
                if (transpose[i][j] > max && hasNoDuplicates(transpose[i], j, transpose[i][j]))
                {
                    max = transpose[i][j];
                    index = j;
                }
                // Take in count special case, thus take the columns index
                else if (!hasNoDuplicates(transpose[i], j, transpose[i][j]))
                {
                    duplicates.insert(i);
                }
            }
            // increase count of index in out array
            if (max > L)
            {
                out[index] += 1;
            }
            int dup_ind = find_duplicate(transpose[i]);
            // special case when our duplicated value, decides if the
            // settement is the hottest
            if (duplicates.count(i) && transpose[i][dup_ind] == max)
            {
                out[take_dup_index(transpose[i], transpose[i][dup_ind])]++;
            }
        }
    }
    else
    {
        out[0]++;
    }

    // take out the index with the biggest value
    int biggest = give_biggest(out);

    // transer in human readable format
    cout << "The warmest settlement is:\n";
    cout << biggest + 1 << endl;
    return 0;
}
