//
//  main.c
//  learning
//
//  Created by Andrei Cristea on 2020. 03. 30..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>

int legnth(char* str){
    int i;
    for(i = 0;str[i] != '\n';i++){
        ;
    }
    return i;
};

//int strcmp(char* st1, char* st2){
//    for(int i = 0){
//        if(same){
//            return 0;
//        }else{
//            return -1;
//        }
//    }
//};

int main(int argc, const char * argv[]) {
    char word[] = "apple";
    char word2[2] = {'a','p', 'p', 'l', 'e', '\0'};
    printf(legnth(word));
    return 0;
}
