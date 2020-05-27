//
//  main.cpp
//  reverse
//
//  Created by Andrei Cristea on 2020. 04. 02..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>

using namespace std;

int lengthString(string text){
    int len = 0;
    while(text[len] != '\0'){
        len++;
    }
    return len;
};


string reverseString(string text){
    string reversed = "";
    for(int i = lengthString(text); i >= 0; i-- ){
        reversed += text[i];
    }
    return reversed;
};

int main(int argc, const char * argv[]) {
    string S = "almafa";
    string R = "";

    cout << R << endl;
    return 0;
}
