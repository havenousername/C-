//
//  main.cpp
//  multiset
//
//  Created by Andrei Cristea on 2020. 05. 26..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

// The MultiSet type representation
#include <iostream>
#include <set>

using namespace std;

template<typename T>


struct SetItem {
    T value;
    int multi;
};

struct Set{
    int cnt;
    int item[];
};

struct MultiSet {
    int cnt;
    SetItem<int> item[];
};




// The multiset type, operations
// ToMultiSet() - puts an element to the multiset
MultiSet ToMultiSet(MultiSet& s, int value){
    int i = 1;
    while (i <= s.cnt && s.item[i].value != value) {
        i++;
    }
    if( i <= s.cnt) {
        s.item[i].multi = s.item[i].multi++;
    }else{
        s.cnt++;
        s.item[s.cnt].value = value;
        s.item[s.cnt].multi = 1;
    }
    return s;
};
// FromMultiSet() - discards an element from multiset
MultiSet FromMultiSet(MultiSet& s, int value){
    int i = 1;
    while (i <= s.cnt && s.item[i].value != value) {
        i++;
    }
    if (i <= s.cnt) {
        if (s.item[i].multi == 1) {
            s.item[i] = s.item[s.cnt];
            s.cnt--;
        }else{
            s.item[i].multi--;
        }
    }
    return s;
}
// Read() - cin multiset
void Read(MultiSet s){
    for (int i = 0; i < s.cnt; i++) {
        cin >> s.item[i].value >> s.item[i].multi;
    }
}
// Write()- writing out the multiset
void Write(MultiSet s){
    for (int i = 0; i < s.cnt; i++) {
        cout << s.item[i].value << " " << s.item[i].multi;
    }
}
// Empty() - create an empty multiset
MultiSet Empty(MultiSet s){
    s.cnt = 0;
    return s;
}
// isEmpty() - check if MS(multiset) is empty
bool isEmpty(MultiSet s){
    if (s.cnt == 0) {
        return true;
    }
    return false;
}
// isElement() - is this element in MS
bool isElement(MultiSet& s, int value){
    int i = 1;
    while (i <= s.cnt && s.item[i].value != value) {
        i++;
    }
    return (i <= s.cnt);
}
// isInTheMultiset() - is an set with given multiplicity multiset
bool isInTheMultiset(SetItem<int> e, MultiSet& s){
    int i = 1;
    while(i <= s.cnt && s.item[i].value != e.value){
        i++;
    }
    return (i <= s.cnt);
};

// multiplicity() - what is the multiplicity of the multiset
int Multiplicity(MultiSet& s, int value){
    int i = 1;
    while (i<s.cnt && s.item[i].value != value) {
        i++;
    }
    if (i < s.cnt) {
        return s.item[i].multi;
    }
    return 0;
}


// MS * MS operations
// Intersection()
//MultiSet Intersection(MultiSet& s1, MultiSet& s2){
//    
//}
// Union()
MultiSet Union(MultiSet& s1,MultiSet& s2){
    MultiSet u;
    u.cnt = u.cnt;
    // copy pattern
    for (int i = 1 ; i <= s1.cnt; i++) {
        u.item[i].multi = s1.item[i].multi;
        u.item[i].value = s1.item[i].multi;
    }
    // selection with decision
    for (int i = 1; i <= s2.cnt; i++) {
        int j = 1;
        while (j < s2.cnt && s2.item[i].value != s2.item[i].value) {
            j++;
        }
        if (j > s1.cnt) {
            u.cnt++;
            u.item[u.cnt] = s2.item[i];
        }else{
            u.item[j].multi += s2.item[i].multi;
        }
    }
    return u;
};
// Difference()
// Max()
// Subset()
bool isSubset(MultiSet& s, MultiSet& e){
    int i = 1;
    while (i<= s.cnt && isInTheMultiset(s.item[i], e)) {
        i++;
    }
    return (i <= s.cnt);
};
// AllCommon()
 
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
