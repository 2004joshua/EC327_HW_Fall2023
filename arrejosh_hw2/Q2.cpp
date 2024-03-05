//
//  main.cpp
//  hw2_q2
//
//  Created by Joshua Arrevillaga on 9/22/23.
//

#include <iostream>
#include <cmath>

double input(){
    double num;
    
    std::cout << "Enter a fractional number: ";
    std::cin >> num;
    
    return num;
}

int main(){
    
    int sign;
    int counter = 0;
    double num, decrement = 0.1, increment = 10.0;
    
    num = input();
    
    std::cout << "In normalized form: \n";
    
    sign = (num >= 1.0 || num <= -1.0 ) ? 1 : -1;
    double factor = (std::abs(num) > 10) ? decrement : increment;
    
    
    if(num == 0){
        std::cout << "Mantissa: " << num;
        std::cout << ", Exponent: " << counter << std::endl;
    }
    else{
        while(std::abs(num) >= 10.0 || std::abs(num) < 1.0){
            num *= factor;
            counter += 1;
        }
    }
    
    std::cout << "Mantissa: " << num;
    std::cout << ", Exponent: " << counter * sign << std::endl;
    
    return 0;
}
