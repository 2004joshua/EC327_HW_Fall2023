#include <iostream> 
#include <cctype> 
#include "Stack.h"

bool parCheck(const std::string &expression){
    Stack<char> stack;
    for(char ch : expression){
        if(ch == '('){
            stack.push(ch); 
        }
        else if(ch == ')'){
            if(stack.isEmpty() || stack.pop() != '('){
                return false; 
            }
        }
    }

    return stack.isEmpty(); 
}

int main(){

    std::string expression; 
    std::cout << "Gimme expression: ";
    std::getline(std::cin , expression);

    (parCheck(expression)) ? 
    std::cout << "Correct Expression" << std::endl : 
    std::cout << "Incorrect Expression" << std::endl;

    return 0; 
}