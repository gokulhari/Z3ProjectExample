#include <iostream>
#include <vector>
#include "z3++.h"
#include "dumClass.h"

using namespace std;



int main (){
    cout << "Hi My name is Gokul.\n";
    z3::context c;
    z3::expr a1 = c.bool_const("a1");
    dumClass a2(c);
    z3::expr b2 = a2.Something(2);
    // z3::expr a3 = a1 && b2;
    // cout << to_string(a3) << endl;
    return 0;
}