//
//  main.cpp
//  thickest
//
//  Created by Andrei Cristea on 2020. 03. 31..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n = 0, counter = 0, index = 0;
    cin >> n;
    int arr[n];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] > counter) {
            index = i;
            counter = arr[i];
        }
        if(counter == 0){
            index = 1;
        }
    }
    cout << index << endl;
    return 0;
}
