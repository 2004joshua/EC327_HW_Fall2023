#include <iostream>
#include <sstream>

//Include other libraries if needed
//
//
//

using namespace std;


//Rectangle class definition
//DO NOT modify the definition
class Rectangle{
public:
  Rectangle(int width, int height, int x, int y);

  int getHeight() const;

  int getWidth() const;

  int getOverlapArea(const Rectangle & r) const;

  string getCoordinates() const;
  
private:
  int width, height, x, y;
};

