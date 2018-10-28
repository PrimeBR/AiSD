#include <iostream>
#include <string>
#include <algorithm> 
#include "stack.hpp"

bool isOperator(char c) {    
    return (!isalpha(c) && !isdigit(c));
} 

int getPriority(char c) { 
    if (c == '-' || c == '+') 
        return 1; 
    else if (c == '*' || c == '/') 
        return 2; 
    else if (c == '^') 
        return 3; 
    return 0; 
} 
  
std::string infixToPostfix(std::string infix) { 
    infix = '(' + infix + ')'; 
    int length = infix.size(); 
    Stack<char> stack; 
    std::string output; 
  
    for (int i = 0; i < length; i++) { 
  
        if (isalpha(infix[i]) || isdigit(infix[i]))     //Если символ является операндом, добавьте его в вывод
            output += infix[i];  
        else if (infix[i] == '(')                       //Если символ равен '(', закидываем его в стек 
            stack.push('('); 
        else if (infix[i] == ')') {                     //Если отсканированный символ является ')', добавляем в вывод и удаляем символы, пока не будет встречен символ '('.
            while (stack.top() != '(') { 
                output += stack.top(); 
                stack.pop(); 
            }  
            stack.pop();  
        }  
        else {              
            if (isOperator(stack.top())) {             //Если оператор, добавляем операторы в вывод в соответствии с приоритетом и удаляем из стека
                while (getPriority(infix[i]) <= getPriority(stack.top())) { 
                    output += stack.top(); 
                    stack.pop(); 
                }                                        
                stack.push(infix[i]); 
            }
        }
    } 
    return output; 
} 

int isValid (std::string infix){
    int length = infix.size();
    int signum_count = 0;
    int alpha_count = 0;
    for(int i = 1; i < length; i++) {
        if(isOperator(infix[i-1]) && infix[i-1] != '(' && infix[i-1] != ')') {
            if(isOperator(infix[i]) && infix[i] != '(' && infix[i-1] != ')') {
                    std::cout << "Two operators in a row!" << std::endl;
                    return 0;
            }
        }
        if(isalpha(infix[i-1]) || isdigit(infix[i-1])){
            if(isalpha(infix[i]) || isdigit(infix[i])) {
            std::cout << "Two letters or numbers in a row!" << std::endl;
            return 0;
        }
        }
        
    }
    
    unsigned int bracket_count = 0;

    for(int i = 0 ; i < length; i++){
        if(isOperator(infix[i]) && infix[i] != ')' && infix[i] != '(') {
            ++signum_count;
            if(!(infix[i] == '-' || infix[i] == '*' || infix[i] == '+' || infix[i] == '/' || infix[i] == '^')) {
                std::cout << "Operator is not valid!" << std::endl;   
                return 0; 
            }
        }

        if(isalpha(infix[i]) || isdigit(infix[i]))
            ++alpha_count;

        if (infix[i] == '(')                               
            ++bracket_count;                                
        if (infix[i] == ')')
            --bracket_count;
        if(i == length-1 && bracket_count != 0){
            std::cout << "Different number of brackets!" << std::endl;
            return 0;                                       
        }                                                   
        if(infix[0] == ')') {
            std::cout << "Incorrect input! Expression started with ')'" << std::endl;
            return 0;
        }

    }

    if(signum_count >= alpha_count ) {
        if(signum_count == alpha_count  && signum_count == 0 && alpha_count == 0){
            std::cout << "Is empty!" << std::endl;
            return 0;
        }
        std::cout << "Invalid input! The number of operators greater than or equal to number of letters(numbers)" << std::endl;
        return 0;
    }

    return 1;
}

int main() 
{ 
    std::string s;
    std::cout << "Expression in infix notation: ";
    std::getline(std::cin, s);
    std::cout << s << std::endl;
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end()); //удаляет все пробелы из строки, перемещая их в её конец, а затем стирая
    int flag = isValid(s);
    if(flag){
        std::cout << "Expression in postfix notation: ";
        std::cout << infixToPostfix(s) << std::endl;
    } 
    return 0; 
} 