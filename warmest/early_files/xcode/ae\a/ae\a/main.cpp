
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

struct count_and_max
{
    int count;
    int max;
};

int find_duplicate(vector<int> v){
    int i = 0;
    for(int j = 0; j < v.size(); j++){
        i = 0;
        while((i < v.size() && v[i]!=v[j]) || i == j){
            i++;
        }
        if(i < v.size()){
            break;
        }
    }
    return i;
};

int take_dup_index(vector<int> v, int d){
    int j = 0;
    while (j < v.size() && d != v[j]) {
        j++;
    }
    if (j < v.size()) {
        return j;
    }else{
        return 0;
    }
};

big give_biggest(vector<count_and_max> out)
{
    big biggest = {0, true} ;
    int cnt = 0;
    // cout << 2 << ":" << out[2].count << endl;
    for (int i = 0; i < out.size(); i++)
    {
        // cout << "Count: index" << i << " count: " << out[i].count << " cnt: " << cnt << endl;
        if (out[i].count > cnt)
        {
            biggest.biggest = i;
            cnt = out[i].count;
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

    vector<count_and_max> out(N);
    set<int> duplicates;

    if (N > 1)
    {
        for (int i = 0; i < transpose.size(); i++)
        {
            int max = L;
            int index = 0;
            for (int j = 0; j < transpose[i].size(); j++)
            {
                if (transpose[i][j] > max && hasNoDuplicates(transpose[i], j, transpose[i][j]))
                {
                    max = transpose[i][j];
                    index = j;
                }
                else if(!hasNoDuplicates(transpose[i], j, transpose[i][j]))
                {
                    duplicates.insert(i);
                }
            }
            if (max > L)
            {
                out[index].count += 1;
                out[index].max = max;
            }
            int dup_ind = find_duplicate(transpose[i]);
            if (duplicates.count(i) && transpose[i][dup_ind] == max)
            {
                out[take_dup_index(transpose[i], transpose[i][dup_ind])].count++;
            }
        }
    }
    else
    {
        out[0].count++;
    }
    big biggest = {1, true};
    biggest = give_biggest(out);
    if(!biggest.isUnique){
        std::set<int>::iterator it;
        for(it = duplicates.begin(); it != duplicates.end(); ++it){
            for (int j = 1; j < out.size(); j++)
            {
                if (out[j].count == out[j - 1].count)
                {
                    if (transpose[*it][j] > transpose[*it][j-1])
                    {
                        out[j].count++;
                        
                    }else{
                        out[j-1].count++;
                    }
                }
            }
        }
        biggest = give_biggest(out);
    }

    // std::set<int>::iterator it;
    // for(it = duplicates.begin(); it != duplicates.end(); ++it){
    //     cout << *it << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < out.size(); i++)
    // {
    //     cout << i << "  " << out[i] << endl;
    // }

    cout << biggest.biggest + 1;
    return 0;
}
