#include <iostream>
#include <typeinfo>
using namespace std;

class Dessert
{
    public: 
    Dessert()
    {
        calories = 10;
    }
    
    //Add destructor here
    virtual ~Dessert(){
        cout << "Destroying a dessert. How horrible!" << endl;
    }

    
    virtual double getCalories()
    {
        return calories;
    }
    
    virtual void printDetails()
    {
        cout << "Calories of " << typeid(*this).name() << " : " << calories << "\n";
        //change this to *this to accurately depict the class
        return;
    }
    
    protected:
        double calories;
};


//Put Tiramisu class here
//Keep the cout statement as the only thing in the destructor
class Tiramisu : public Dessert {
    public:
        ~Tiramisu() override {
            cout << "Destroying a Tiramisu. You monster!" << endl;

        }
};



//Add non-member eat function here
void eat(Dessert *ptr){

    if(typeid(*ptr) == typeid(Tiramisu)) {
        cout << "Ate dessert!" << endl; // If you can eat it
        return;
    }
    else{
        cout << "You can't eat a generic dessert!" << endl; //if you can't eat it
        return;
    }

}





int main()
{
  Dessert *dPtr = new Dessert;
  dPtr->printDetails();
  
  //Uncomment once Tiramisu class is created

  //add a line here for to make tPtr for Tiramisu object
  //
  //
  //
  Dessert *tPtr = new Tiramisu;

  tPtr->printDetails();
  eat(tPtr);
 
  eat(dPtr);
  
  delete tPtr;

  
  delete dPtr;

  return 0;
}
