//
//  main.cpp
//  HW2_Q1
//
//  Created by Joshua Arrevillaga on 9/21/23.
//

#include <iostream>
#include <cmath>
#include <iomanip>

int parameter_x(){
    int x;
    std::cout << "X: ";
    std::cin >> x;
    return x;
}

int parameter_y(){
    int y;
    std::cout << "Y: ";
    std::cin >> y;
    return y;
}

int parameter_r(){
    int r;
    std::cout << "R: ";
    std::cin >> r;
    return r;
}

double magnitude(int x1, int x2, int y1, int y2){
    
    double magnitude = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    return magnitude;
}


int main() {
    
    int x1, x2, y1, y2, r1, r2;
    double d;
    
    std::cout << "Enter the coordinates and radius for the first circle \n";
    x1 = parameter_x();
    y1 = parameter_y();
    r1 = parameter_r();
    
    std::cout << "Enter your coordinates and radius for the second circle \n";
    x2 = parameter_x();
    y2 = parameter_y();
    r2 = parameter_r();
    
    d = magnitude(x1,x2,y1,y2);
    
    bool overlap = (d < (r1 + r2)); //takes in boolean value if d is less than the combined radius
    
    if(overlap){
        std::cout << "THE CIRCLES OVERLAP." << std::endl;
    }
    else{
        d = d - r1 -r2;
        std::cout << "THE MINIMUM DISTANCE BETWEEN THE CIRCLES IS " << std::fixed << std::setprecision(2) << d << std::endl;
    }

    return 0;
}
