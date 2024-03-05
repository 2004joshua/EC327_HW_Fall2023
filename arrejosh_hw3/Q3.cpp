#include <iostream> 
#include <cmath> 
#include <iomanip> 

double guessSqrt(double num);

int main(){

    double num, estimate, correct; 

    std::cout << "Enter a positive number: ";
    std::cin >> num;

    estimate = std::abs(guessSqrt(num) - sqrt(num));


    std::cout << "The absolute difference between the correct square root and the function’s result is " << std::scientific << std::setprecision(5) << estimate << std::endl;
    return 0; 
}
double guessSqrt(double num){

    double initial = num; 
    double next; 
    double condition = 0.001;

    while(true){
        next = (initial + (num / initial)) / 2.0; 

        if(std::abs(next - initial) < condition){
            return next; 
        }

        initial = next;
    }
}