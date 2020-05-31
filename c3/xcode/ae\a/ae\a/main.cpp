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

int maximum_temp(vector<int> v)
{
    int max = 0;
    int index = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (max > v[i])
        {
            max = v[i];
            index = i;
        }
    }
    return max;
}

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
    vector<vector<int> > weather(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> weather[i][j];
        }
    }
    vector<vector<int> > transpose(M);
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            transpose[j].push_back(weather[i][j]);
        }
    }

    vector<int> out(N);
    set<int> duplicates;

    if (N > 1)
    {
        for (int i = 0; i < transpose.size(); i++)
        {
            int max = 0;
            int index = 0;
            for (int j = 0; j < transpose[i].size(); j++)
            {
                if (transpose[i][j] > max && hasNoDuplicates(transpose[i], j, transpose[i][j]))
                {
                    max = transpose[i][j];
                    index = j;
                }
                else if (transpose[i][j] > max && !hasNoDuplicates(transpose[i], j, transpose[i][j]))
                {
                    index = j;
                    duplicates.insert(i);
                    max = max*max;
                }
            }
            if (max > L && max < 50)
            {
                out[index]++;
            }
            else if(duplicates.count(i))
            {
                for (int j = 0; j < transpose[i].size(); j++)
                {
                    if (out[index] == out[j] && transpose[i][j] < transpose[i][index] && index != j)
                    {
                        out[index]++;
                    }
                }
             }
        }
    }
    else
    {
        out[0]++;
    }

    //    std::set<int>::iterator it;
    //    for(it = duplicates.begin(); it != duplicates.end(); ++it){
    //        cout << *it << " ";
    //    }
    //    cout << endl;

    for(int i = 0; i < out.size(); i++){
        cout << i << "  " << out[i] << endl;
    }
    cout << endl;

    int biggest = give_biggest(out);
    cout << biggest + 1;
    return 0;
}

