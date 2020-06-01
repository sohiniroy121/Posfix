//
// Created by Sohini Roy on 5/29/20.
//

#ifndef UNTITLED2_POSFIX_H
#define UNTITLED2_POSFIX_H

#include <string>
#include <stack>
#include <vector>

using std::string;
using std::stack;
using std::vector;

class Posfix {
public:
    static int Calculate(string expression);
    static bool CheckValidString(string expression);
};


#endif //UNTITLED2_POSFIX_H
