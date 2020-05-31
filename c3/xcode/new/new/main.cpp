// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

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

bool is_the_biggest_count(vector<int> out, int dup_ind)
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
    
    return dup_ind == cnt;
};

bool hasNoDuplicates(vector<int> v, int limit, int i)
{
    int j = 0;
    while ((j < limit && i != v[j]))
    {
        j++;
    }
    return (j == limit);
};

int main()
{
    int N = 0, M = 0, L = 0;
    cin >> N >> M >> L;
    vector<vector<int>> weather(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> weather[i][j];
        }
    }
    vector<vector<int>> transpose(M);
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            transpose[j].push_back(weather[i][j]);
        }
    }

    vector<int> out(N);

    if (N > 1)
    {
        for (int i = 0; i < transpose.size(); i++)
        {
            int max = 0;
            int index = 0;
            for (int j = 0; j < transpose[i].size(); j++)
            {
                if (transpose[i][j] > max && hasNoDuplicates(transpose[j], j, transpose[i][j]))
                {
                    max = transpose[i][j];
                    index = j;
                }
            }
            if (max > L)
            {
                out[index]++;
            }
        }
    }
    else
    {
        out[0]++;
    }

    int biggest = give_biggest(out);
    cout << biggest + 1;
    return 0;
}

