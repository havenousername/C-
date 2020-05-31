// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct big
{
    int biggest;
    bool isUnique;
};


big give_biggest(vector<int> out)
{
    big biggest = {0, true} ;
    int cnt = 0;

    for (int i = 0; i < out.size(); i++)
    {
        if (out[i] > cnt)
        {
            biggest.biggest = i;
            cnt = out[i];
        }
        else if(out[i] == cnt)
        {
            biggest.isUnique = false;
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
                    duplicates.insert(i);
                    cout << "Value: " << i << " Max: "<< max  << endl; 
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
    // big biggest = {1, true};
    // biggest = give_biggest(out);
    // if(biggest.isUnique == false ){
    //     std::set<int>::iterator it;
    //     for(it = duplicates.begin(); it != duplicates.end(); ++it){
    //         for (int j = 1; j < out.size(); j++)
    //         {
    //             if (out[j] == out[j - 1])
    //             {
    //                 if (transpose[*it][j] > transpose[*it][j-1])
    //                 {
    //                     cout <<"Count muther*ka: "<< out[j] << " Index: " << j << endl;
    //                     out[j]++;
    //                 }
    //             }
    //         }
    //     }
    //     biggest = give_biggest(out);
    // }
    

    // //    std::set<int>::iterator it;
    // //    for(it = duplicates.begin(); it != duplicates.end(); ++it){
    // //        cout << *it << " ";
    // //    }
    // //    cout << endl;

    // for (int i = 0; i < out.size(); i++)
    // {
    //     cout << i << "  " << out[i] << endl;
    // }
    // cout << endl;

    // cout << biggest.biggest + 1;
    return 0;
}
