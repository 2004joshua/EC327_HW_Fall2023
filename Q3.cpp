
#include <iostream> 
#include <iomanip>


int main(){

   unsigned int 
   num1, num2;

    do{

        std::cout << "Enter two non-negative integers: "; 
        std::cin >> num1 >> num2; 

    }while(num1 < 0 || num2 < 0);

    unsigned int 
    digit_changes = 0;

    for(int i = 1; i <= 8; i++){
        unsigned int 
        hex1 = (num1 >> (i * 4)) & 0xF,
        hex2 = (num2 >> (i * 4)) & 0xF;
        if (hex1 != hex2){
            digit_changes++;
        }

    }

    std::cout << "These numbers differ in " << digit_changes << " hex digits." << std::endl;
    
    return 0; 
}