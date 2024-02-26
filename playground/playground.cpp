//
// Created by Hà Tường Nguyên on 2/25/24.
//

#include "playground.h"
#include <cassert>
#define assertm(exp, msg) assert(((void)msg, exp))

int main() {
    cout << GREEN << "START" << RESET << endl;

    assertm((2 + 2) % 3 == 0, "Success");

    cout << GREEN << "END" << RESET << endl;
    return 0;
}
