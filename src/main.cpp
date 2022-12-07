#include <iostream>
#include <vector>
#include "z3++.h"
#include "dumClass.h"

using namespace std;

int main (){
    z3::context c;
    z3::expr a1 = c.bool_const("a1");
    dumClass d1(c);
    z3::expr a2 = d1.Something(2);
    z3::expr a3 = a1 && a2;
    cout << to_string(a3) << endl;
    return 0;
}