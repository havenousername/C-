//
//  main.c
//  struct.c
//
//  Created by Andrei Cristea on 2020. 04. 03..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>

struct binary {
    int x;
    int y;
};

int main(int argc, const char * argv[]) {
    struct binary arr[] = {
        {2,3},
        {4,5},
        {1,5},
        {4,3},
        {1,2},
    };
    
    for (int i = 0; i <= (sizeof(arr) /8)-1 ; i++) {
        int j = 1;
        for (int i = 0; i < sizeof(arr)/8; i++) {
            int numberXOne = arr[i].x;
            int numberXTwo = arr[j].x;
            int numberYOne = arr[i].y;
            int numberYTwo = arr[j].y;
            if((arr[i].x > arr[j].x) && (j < sizeof(arr)/8)){
                arr[i].x = numberXTwo;
                arr[j].x = numberXOne;
                arr[i].y = numberYTwo;
                arr[j].y = numberYOne;
            }else{
                arr[i].x = numberXOne;
                arr[j].x = numberXTwo;
                arr[i].y = numberYOne;
                arr[j].y = numberYTwo;
            }
            int n1 =arr[i].y;
            int n2 = arr[j].y;
            if ((arr[i].y > arr[j].y) && (arr[i].x == arr[j].x)) {
                arr[i].y = n2;
                arr[j].y = n1;
            }
            
            j++;
        }
    }
    
    for (int i = 0; i < sizeof(arr)/8; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
    return 0;
}
