//
//  main.cpp
//  ae\a
//
//  Created by Andrei Cristea on 2020. 05. 30..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>

struct Eq
{
    bool operator()(bool lv, bool rv) const
    {
        return lv == rv;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
