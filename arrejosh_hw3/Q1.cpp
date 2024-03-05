//This code will give me the taylor approximation up to int n
//this code will also give me the approximation n that will give me a difference less than 0.01

#include <iostream> 
#include <cmath> 
#include <iomanip> 

double ExpTaylor(int x, int n);
long double factorial(int n); 
int minterm(int x);


int main(){ 

    int x, n;
    double exp_result;

    std::cout << "Enter x: ";
    std::cin >> x; 
    std::cout << "Enter n: ";
    std::cin >> n; 


    exp_result = ExpTaylor(x, n); 


    std::cout << "ExpTaylor result: " << std::fixed << std::setprecision(1) << exp_result << std::endl; 
    std::cout << "exp(x) result: " << std::fixed << std::setprecision(3) << exp(x) << std::endl; 

   
    n = minterm(x);

    std::cout << "Minimum n for a difference of at most 0.01: " << n << std::endl;

    return 0; 
}


//in order to make this work according to the outputs, i started indexing at 1
double ExpTaylor(int x, int n){
     

    if(n == 1){
        return 1.0; 
    }

    double result = pow(x , n-1) / static_cast<double>(factorial(n - 1));

    return result + ExpTaylor(x,n-1);
}



long double factorial(int n){ 

    if (n == 1 || n == 0){

        return 1.0; //0! = 1

    }
    else if (n > 1) {

        long double factorial = 1.0;

        for(int i = 1; i <= n; i++){

            factorial*=i;

        }

        return factorial;
    }
    else{

        return 1.0; //incase a negative value is inputted 

    }
    
}

int minterm(int x){

    int n = 1; //indexing starts at 1
    double threshold = 0.01; 
    double result; 

    do{
        
        result = ExpTaylor(x,n);
        n++; 

    }while(std::abs(exp(x) - result) > threshold);
    return n - 1;
}
