/*
Created by: Andrei Cristea

Neptun: W61RAB
E-mail: cristea.andrei997@gmail.com

Task: „C3 - Closest islands

*/

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <limits>
#include <string>

using namespace std;

template <class T>

T validate_input(const T low, const T high, const string &message, const string &error, const string &mismatch)
{
    T input = low - 1;
    while (input < low || input > high)
    {
        cout << message;

        while ((cin >> input).fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << error;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (input < low || input > high)
        {
            cerr << mismatch;
        }
    }
    return input;
}

vector<int> split_to_int(const string &s, char delimeter)
{
    vector<int> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimeter))
    {
        try
        {
            if (stoi(token) >= 0 && stoi(token) <= 50)
            {
                tokens.push_back(stoi(token));
            }
        }
        catch (exception &err)
        {
            cerr << "Error. Input should be integer\n";
            break;
        }
    }
    return tokens;
};

bool all_less_than_L(vector<vector<int>> v, int M)
{
    int counter = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (auto vi : v[i])
        {
            if (vi <= M)
            {
                counter++;
            }
        }
    }
    return (counter == (v.size() * v[0].size()));
};

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
    return 0;
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

bool has_no_duplicates(vector<int> v, int limit, int i)
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
    int biggest = 0;
    cout << "====Continuosly warmest settlement====\n";
    cout << "Please write down settlements, days and temperature limit\n";
    cout << "Separate each input by new line\n";

    const int min_limit = 1;
    const int max_limit = 1000;
    const string type_error = "Error. Enter integer value\nTry again\n";
    const string limit_error = "Error. Your integer value is out of bound\nTry again\n";

    N = validate_input(min_limit, max_limit, "Settlement\n", type_error, limit_error);
    M = validate_input(min_limit, max_limit, "Day\n", type_error, limit_error);
    L = validate_input(20, 50, "Temperature Limit\n", type_error, limit_error);

    cout << "Next, write down in each column settlement's temperature:\n";
    vector<vector<int>> weather(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        bool repeat = true;
        vector<int> temp;
        while (repeat)
        {
            string str;
            getline(cin, str, '\n');
            temp = split_to_int(str, ' ');
            if (temp.size() < M)
            {
                repeat = true;
                cerr << "Error found in line.\nAll temperatures in settlement should be in range 0<=Temperature<=50\nTry again\n";
            }
            else
                repeat = false;
        }
        for (int j = 0; j < M; j++)
        {
            weather[i][j] = temp[j];
        }
    }

    // First, transpose matrix in order to have simplify task
    vector<vector<int>> transpose(M);
    if (all_less_than_L(weather, L))
    {
        biggest = -2;
    }
    else
    {
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
                    if (transpose[i][j] > max && has_no_duplicates(transpose[i], j, transpose[i][j]))
                    {
                        max = transpose[i][j];
                        index = j;
                    }
                    // Take in count special case, thus take the columns index
                    else if (!has_no_duplicates(transpose[i], j, transpose[i][j]))
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
        biggest = give_biggest(out);
    }
    // transer in human readable format
    cout << "The warmest settlement is:\n";
    cout << biggest + 1 << endl;
    return 0;
}
