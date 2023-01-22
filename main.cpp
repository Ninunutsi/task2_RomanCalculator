#include <iostream>
#include <string>
// veqtoristvis
#include <vector>
#include<bits/stdc++.h> 
#include <regex>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;
    
    // romeli operaciaa gasaketebeli imas eubneba
    double performOperation(char op, double num1, double num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}
    
    // rom gaitvaliswinos romeli moqmedeba unda shesruldes jer
    // anu tanmimdevroba matematikuri operaciebis mati mnishvnelobis mixedvit
    int precedence(char op) {
        if (op == '*' || op == '/')
            return 2;
        if (op == '+' || op == '-')
            return 1;
        return 0;
    }


