
/// Some dum class, to demonstrate problem with z3.
#include <string>
#include "z3++.h"

class dumClass {
    private:
    z3::context &_c;
    public:
    dumClass(z3::context& c):_c(c){};
    z3::expr Something(int k);
};