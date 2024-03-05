#include <iostream>
#include <sstream>
#include "Q2.h"

//Include other libraries if needed
//
//
//

using namespace std;

//Implement Rectangle functions here
//
//
//
Rectangle::Rectangle(int width, int height, int x, int y) {
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
}

int Rectangle::getHeight() const {
    return height;
}

int Rectangle::getWidth() const {
    return width;
}

string Rectangle::getCoordinates() const {

    string x = to_string(this->x);
    string y = to_string(this->y);


    return x + "," + y;
}

int Rectangle::getOverlapArea(const Rectangle & r) const {
    int lside = max(this->x, r.x); //max left coord between r and this
    int rside = min(this->x + getWidth(), r.x + r.getWidth()); //min right coord between r and this
    int tside = max(this->y , r.y); //max y coord between r and this
    int bside = min(this->y + getHeight(), r.y + r.getHeight()); //min y coord between r and this

    if(lside < rside && tside < bside){
        int overlapW = rside - lside;
        int overlapH = bside - tside;

        return overlapH * overlapW;
    }

    return 0;

}





//Hint:
  //To convert integers to strings, you can use stringstream if you like:
  //int a = 10;
  //stringstream ss;
  //ss << a;
  //string str = ss.str();




int main()
{
  //Uncomment once Rectangle class is created
  //DO NOT modify the test code

  Rectangle r1(4,3,0,0), r2(2,1,3,0);  // (width, height, x, y)
   
  cout << "Overlap area of a rectangle with height "
       << r1.getHeight() << " and width " << r1.getWidth()
       << " at coordinates " << r1.getCoordinates()
       << " and a rectangle with height "
       << r2.getHeight() << " and width " << r2.getWidth()
       << " at coordinates " << r2.getCoordinates()
       << " is: " << r1.getOverlapArea(r2) << endl;
  
  //This code should print on the console:
  //Overlap area of a rectangle with height 3 and width 4 at coordinates 0,0 and a rectangle with height 1 and width 2 at coordinates 3,0 is 1


  //Put your additional test code here
  /*Follow the sample run:
  "Enter height, width, x coordinate, and y coordinate of a rectangle:"
  <user enters four numbers separated by spaces and hits enter>
  Enter height, width, x coordinate, and y coordinate of another rectangle:
  <user enters four numbers separated by spaces and hits enter>
  Overlap area: ... */
  int x1, x2, y1, y2, height1, height2, width1, width2;
  cout << "Enter height, width, x coordinate, and y coordinate of a rectangle: \n";
  cin >> height1 >> width1 >> x1 >> y1;
  cout << "\n";

  cout << "Enter height, width, x coordinate, and y coordinate of another rectangle: \n";
  cin >> height2 >> width2 >> x2 >> y2;

  Rectangle R1(height1, width1,x1,y1), R2(height2,width2,x2,y2);

  cout << "Overlap area: " << R1.getOverlapArea(R2) << endl;


    return 0;
}

