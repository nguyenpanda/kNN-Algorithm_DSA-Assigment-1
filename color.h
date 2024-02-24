//
// Created by Hà Tường Nguyên on 2/24/24.
//

#ifndef DSA_ASSIGNMENT_COLOR_H
#define DSA_ASSIGNMENT_COLOR_H

#include <iostream>
#include <string>

namespace color {

    const std::string
            GREEN = "\033[1;92m",
            RED = "\033[1;31m",
            CYAN = "\033[1;96m",
            YELLOW = "\033[1;93m",
            MAGENTA = "\033[1;95m",
            BLUE = "\033[1;94m",
            GREEN_BACKGROUND = "\033[42;97m",
            RED_BACKGROUND = "\033[41;97m",
            CYAN_BACKGROUND = "\033[46;97m",
            YELLOW_BACKGROUND = "\033[43;97m",
            MAGENTA_BACKGROUND = "\033[45;97m",
            BLUE_BACKGROUND = "\033[44;97m",
            RESET = "\033[0m";
}

#endif //DSA_ASSIGNMENT_COLOR_H
