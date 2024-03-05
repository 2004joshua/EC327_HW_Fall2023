#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
  Animal(string name,  float weight);
 
  virtual string getName() const;
  virtual float getWeight() const;
  virtual void printInfo() const;
 
protected://changed
  string name;
  float weight; //in pounds
};

Animal::Animal(string name, float weight)
{
  this->name = name;
  this->weight = weight;
}
 
string Animal::getName() const
{
  return name;
}
 
float Animal::getWeight() const
{
  return weight;
}
 
void Animal::printInfo() const
{
  cout<<"Animal "<<name<<" is "<<weight<<" lbs."<<endl;
}

//Put Dog class here
//Use the following constructor prototype:
//  Dog(string name, float weight, string breed);
//
//

class Dog : public Animal{
  private: 
  string breed; 

  public: 
  
  Dog(string name, float weight, string breed); 
  friend bool operator>(const Dog &a1, const Dog &a2);
  string getbreed() const; 
  void printInfo() const;

};

bool operator>(const Dog &a1, Dog &a2){
  return a1.getWeight() > a2.getWeight(); 
}

Dog::Dog(string name, float weight, string breed) 
  : Animal(name, weight), breed(breed) {
    this->breed = breed; 
  }

string Dog::getbreed() const {
  return breed;
}

void Dog::printInfo() const {
  cout << "Dog " << name << " is a " << breed << " and weighs " << weight << " lbs." << endl; 
}

bool isEqualWeight(Animal &a1, Animal &a2) { //do NOT modify this function
  a1.printInfo();
  a2.printInfo();
  if (a1.getWeight()==a2.getWeight()) return 1;
  else return 0;
}
 
int main () {
  //Uncomment once the Dog class is created
  //DO NOT modify the test code
  
  vector<Dog> mydogs;
  mydogs.push_back(Dog("Max", 25, "Beagle"));
  mydogs.push_back(Dog("Maya", 60, "Labrador"));
  cout << isEqualWeight(mydogs[0],mydogs[1]) << endl;
  //This should print the following:
  //Dog Max is a Beagle and weighs 25 lbs.
  //Dog Maya is a Labrador and weighs 60 lbs.
  //0

  
  if (mydogs[0]>mydogs[1]) 
    cout << mydogs[0].getName() << " is heavier than "
         << mydogs[1].getName() << endl;
  else if (mydogs[1]>mydogs[0])
    cout << mydogs[1].getName() << " is heavier than "
         << mydogs[0].getName() << endl;
  else
    cout << mydogs[1].getName() << " and "
         << mydogs[0].getName() << " have the same weight\n";
  //This should print the following:
  //Maya is heavier than Max
  



  // Put your additional test code here if needed
  //
  //
  //




  return 0;
}