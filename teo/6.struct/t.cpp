#include <iostream>
#include <cstring>

typedef char string[64];

struct Bar {
    float xd;
};

struct Foo {
    
    int var1;
    int var2;
    string var3;

    Bar var4[50];

};

int main() {

    Foo foo;
 
    return 0;
}