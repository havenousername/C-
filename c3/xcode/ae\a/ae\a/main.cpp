// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct maximum{
    int count;
    bool isUnique;
    bool biggerThanL;
};

int give_biggest(vector<maximum> out)
{
    int biggest = 0;
    int cnt = 0;

    for (int i = 0; i < out.size(); i++)
    {
        if (out[i].count > cnt)
        {
            biggest = i;
            cnt = out[i].count;
        }
    }
    return biggest;
};

bool is_the_biggest_count(vector<maximum> out, int dup_ind)
{
    return dup_ind == (give_biggest(out));
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

    vector<maximum> out(N);

    if (N > 1)
    {
        for (int i = 0; i < transpose.size(); i++)
        {
            int max = 0;
            int index = 0;
            int isUnique = false;
            for (int j = 0; j < transpose[i].size(); j++)
            {
                if (transpose[i][j] > max && hasNoDuplicates(transpose[i], j, transpose[i][j]))
                {
                    max = transpose[i][j];
                    index = j;
                    isUnique = true;
                }else if(transpose[i][j] > max && !hasNoDuplicates(transpose[i], j, transpose[i][j])){
                    max = transpose[i][j];
                    index = j;
                }
            }
            out[index].count++;
            out[index].isUnique = isUnique;
            if (max > L)
            {
                out[index].biggerThanL = true;
            }else{
                out[index].biggerThanL = false;
            }
        }
    }
    else
    {
        out[0].count++;
    }

    int biggest = give_biggest(out);
    cout << biggest + 1;
    return 0;
}
