
#include <iostream>
#include <string>
#include "Posfix.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    string expression;
    cin >> expression;

    int num = Posfix::Calculate(expression);
    cout << num;
}


