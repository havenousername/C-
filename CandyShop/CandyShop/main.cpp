//
//  main.cpp
//  CandyShop
//  W61RAB
//  Created by Andrei Cristea on 2020. 05. 26..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;

struct factory {
    int factory_id;
    int candy_id;
    int price;
};

struct set{
    int id;
    vector<int> items;
};

struct ex_factory {
    int factory_id;
     int price;
};

// Maximum selection
factory cheapest(vector<factory> f){
    int min = f[0].price;
    factory min_f = f[0];
    for (int i = 1; i < f.size(); i++) {
        if (min > f[i].price) {
            min = f[i].price;
            min_f = f[i];
        }
    }
    return min_f;
};

//


set make_set(int id, int item)
{
  set new_set;
  new_set.id = id;
  new_set.items.push_back(item);
  return new_set;
};

bool isUnique(int candy_id, vector<set> candies){
    int i = 0;
    while (i < candies.size() && candies[i].id != candy_id) {
        i++;
    }
    return (i == candies.size());
}

int find_factory(vector<set> candies, int candy_id){
    int i = 0;
    while (i < candies.size() && candies[i].id != candy_id) {
        i++;
    }
    return i;
};

void modify_set(vector<set> candies,int id, int candy){
    int i = find_factory(candies, id);
    candies[i].items.push_back(candy);
};

// 3rd task
bool isUq(int factory_id, vector<ex_factory> f){
    int i = 0;
    while (i < f.size() && f[i].factory_id != factory_id) {
        i++;
    }
    return (i == f.size());
}

int find_expensive(vector<ex_factory> expensive, int factory_id){
    int i = 0;
    while (i < expensive.size() && expensive[i].factory_id != factory_id) {
        i++;
    }
    return i;
};

bool compare(const ex_factory &a, const ex_factory &b)
{
    return a.factory_id < b.factory_id;
}


// 4rd task
bool isUniqueCandy(int candy_id, int start, vector<factory> f){
    int i = start;
    while (i < f.size() && candy_id != f[i+1].candy_id) {
        i++;
    }
    return (i == f.size());
};

// 5th

bool isUniqueCandyTwo(int candy_id,int j, vector<factory> f){
    int i = 0;
    while ((i < f.size() && candy_id != f[i].candy_id)) {
        i++;
    }
    return (i < f.size());
};

int main(int argc, const char * argv[]) {
    int N,M,K;
    cin >> N >> M >> K;
    vector<factory> factories(N);
    for (int i = 0; i < N ; i++) {
        cin >> factories[i].factory_id >> factories[i].candy_id >> factories[i].price;
    }
    // 1st task
    factory cheap = cheapest(factories);
    cout << cheap.factory_id << " " << cheap.candy_id;
    cout << endl;
    
    // 2nd task
    vector<set> most_candies;
    for (int i = 0; i < factories.size(); i++) {
        if (isUnique(factories[i].factory_id, most_candies)) {
            most_candies.push_back(make_set(factories[i].factory_id, factories[i].candy_id));
        }else{
            modify_set(most_candies, factories[i].factory_id, factories[i].candy_id);
            most_candies[find_factory(most_candies, factories[i].factory_id)].items.push_back(factories[i].candy_id);
        }
    }
    int max = most_candies[0].id;
    long max_size = most_candies[0].items.size();
    for (int i = 0; i < most_candies.size(); i++) {
        if (most_candies[i].items.size() > max_size) {
            max_size = most_candies[i].items.size();
            max = most_candies[i].id;
        }else if(most_candies[i].items.size() == max_size){
            if(most_candies[i].id < most_candies[i].id){
                max_size = most_candies[i].items.size();
                max = most_candies[i].id;
            }
        }
    }
    cout << max << endl;
    
    // 3rd task
    vector<ex_factory> out;
    out.push_back({factories[0].factory_id, factories[0].price});
    for (int i = 1; i < factories.size(); i++) {
        if (isUq(factories[i].factory_id, out)) {
            out.push_back({factories[i].factory_id,factories[i].price});
        }else{
            int j = find_expensive(out, factories[i].factory_id);
//            if (i == 0) {
//                out.push_back({factories[i].factory_id,factories[i].price});
//            }
            if (out[j].price < factories[i].price) {
                out[j].price = factories[i].price;
            }
        }
    }
    cout << out.size() << " ";
//    sort(out.begin(), out.end(), compare);
    for (auto o : out) {
        cout << o.factory_id << " " << o.price << " ";
    }
    cout << endl;
    
    // 4rth task
    
    int count = 0;
    for (int i = 0; i < factories.size(); i++){
        if (isUniqueCandy(factories[i].candy_id, i, factories)) {
            count++;
        }
    }
    cout << count << endl;
    
    // 5th task
    vector<int> unique_candies(K);
    int flag = 0;
    int counting = 0;
//    unique_candies.push_back()
    
    return 0;
}
