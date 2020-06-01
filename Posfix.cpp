//
// Created by Sohini Roy on 5/29/20.
//

#include "Posfix.h"
#include <string>
#include <stack>
#include <vector>
#include <iostream>

using std::string;
using std::stack;
using std::vector;
using std::cout;
using std::endl;


/*
 * Iterates through expression string and creates a stack of all the numbers.
 */
int Posfix::Calculate(string expression) {
    if (!CheckValidString(expression)) {
        cout << "Please input a valid expression" << endl;
        exit(0);
    }
    stack<int> numStack;

    for (int i = 0; i < expression.length(); i++) {
        int intElement;
        if (isdigit(expression.at(i))) {
            intElement = expression.at(i) - '0';
            numStack.push(intElement);
        } else {
            int numberOfItemsToPop = 2;
            vector<int> poppedItems;
            for (int j = 0; j < numberOfItemsToPop; j++) {
                poppedItems.push_back(numStack.top());
                numStack.pop();
            }
            if (expression.at(i) == '+') {
                int toPush = poppedItems.at(1) + poppedItems.at(0);
                numStack.push(toPush);
            } else if (expression.at(i) == '-') {
                int toPush = poppedItems.at(1) - poppedItems.at(0);
                numStack.push(toPush);
            } else if (expression.at(i) == '*') {
                int toPush = poppedItems.at(1) * poppedItems.at(0);
                numStack.push(toPush);
            } else if (expression.at(i) == '/') {
                int toPush = poppedItems.at(1) / poppedItems.at(0);
                numStack.push(toPush);
            }
        }
    }
    return numStack.top();
}

bool Posfix::CheckValidString(string expression) {
    for (int i = 0; i < expression.length(); i++) {
        char element = expression.at(i);
        if (!isdigit(element)) {
            if (element != '+' &&
            element != '-' &&
            element != '*' &&
            element != '/') {
                return false;
            }
        }
    }
    return true;
}

