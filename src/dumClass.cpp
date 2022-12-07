
#include "dumClass.h"

z3::expr dumClass::Something(int k){
    z3::expr temp = _c.bool_const(std::to_string(k).c_str());
    return temp;
};