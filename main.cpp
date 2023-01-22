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
    
// regex simboloebit mowmdeba tu aris sworad dawerili romauli ricxvebi
    bool validationOfRoman(string str){
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        const regex pattern("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
        if (str.empty()) {
            return false;
        }
        if (regex_match(str, pattern)) {
            return true;
        }else{
            return false;
        }
    }
    
int roman_to_int(std::string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    std::map<char, int> roman_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int result = 0;
    int prev = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int current = roman_map[s[i]];
        if (current < prev) {
            result -= current;
        } else {
            result += current;
        }
        prev = current;
    }
    return result;
}
    
    void int_to_roman(int number){
        int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=12;   
        while(number>0){
            int division = number/num[i];
            number = number%num[i];
            while(division--){
                cout<<sym[i];
            }
            i--;
        }
    }

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


int main()
{
    string input;
    vector<int> romanNums;
    string operation;
    vector<string> wholeExample;
    
    while (true) {
        cout << "Enter a Roman number or 'exit' to quit: ";
        cin >> input;
        if (input == "exit") {
            break;
        };
        if(!check_valid_roman(input) || !validationOfRoman(input)){
            cout << "Sorry, you have to a input valid Roman Numeral." << endl;
            cout << "Enter a Roman number or 'exit' to quit: ";
            cin >> input;
        }
        // vectori romelic inaxavs ricxvebs
        // veqtorshi vsvam funqcias romelic abrunebs ricxvs
        int toInt = roman_to_int(input);
        romanNums.push_back(toInt);
        string intToString = to_string(toInt);
        wholeExample.push_back(intToString);
        
        cout << "Enter an operation (+, -, *, /) or 'exit' to quit: ";
        cin >> operation;
        if(operation=="exit"){
            break;
        };
        if(!check_valid_math_operation(operation)){
            cout << "Sorry, you have to input one of the given math operations." << endl;
            cout << "Enter a operation (+, -, *, /) or 'exit' to quit: ";
            cin >> operation;
        }
        
        wholeExample.push_back(operation);
    };
    
    std::ostringstream vectortostring;
    // gadayavs vectori stringshi
    if (!wholeExample.empty()){
        std::copy(wholeExample.begin(), wholeExample.end()-1,
        std::ostream_iterator<string>(vectortostring, ""));
        
        vectortostring << wholeExample.back();
    }
  
   // std::cout << vectortostring.str()<< std::endl;
    string math_expression = vectortostring.str();
    vector<double> numbers;
    vector<char> operations;
    stringstream ss(math_expression);
    double num;
    char op;
        // axarisxebs romeli sheyvanili simboloa ricxvi da romeli matematikuri operacia
        while (ss >> num) {
        numbers.push_back(num);
        if (ss >> op) {
            operations.push_back(op);
        }
    }
    
    for (int i = 0; i < operations.size(); i++) {
        while (i < operations.size() && precedence(operations[i]) == 2) {
            double temp = performOperation(operations[i], numbers[i], numbers[i+1]);
            // washlis gamoyenebul ricxvebs
            operations.erase(operations.begin() + i);
            numbers.erase(numbers.begin() + i, numbers.begin() + i + 2);
            numbers.insert(numbers.begin() + i, temp);
        }
    }
    
    while (operations.size() > 0) {
        double temp = performOperation(operations[0], numbers[0], numbers[1]);
        operations.erase(operations.begin());
        numbers.erase(numbers.begin(), numbers.begin() + 2);
        numbers.insert(numbers.begin(), temp);
    }
    
    cout << "Result: ";
    int_to_roman(numbers[0]);

};
