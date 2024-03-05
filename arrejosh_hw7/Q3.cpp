#include <iostream>
#include <vector>
#include <string> 
#include <cctype> 

//add other libraries if needed

using namespace std;


vector<string> split(const string &expression) {
//returns a vector of strings that represent operands or numbers
//implement your function here

vector<string> result; 
string temp; 

for(char ch : expression){
  if(isdigit(ch)){
    temp += ch; //ch nums will be added to the temp string 
  }
  else if(ch == '+' || ch == '-' || ch == '*' || ch == '%' || ch == '/'){
    result.push_back(temp); //adds new element and inputs temp
    temp.clear(); //clear temp

    result.push_back(string(1,ch)); //makes ch a string and puts in result
    continue; 
  }
  else if(ch == ' '){
    continue; //ignores space
  }
  }

  if(!temp.empty()){
    result.push_back(temp); //incase the last part isnt added it becomes the last element in the vector
  }

  return result; 
}


 
int main () {
  //test code: 
  //ask the user to enter an expression
  //call the split function
  //display the split items (numbers and operands) on the console
  

  vector<string> result = split("36*4+5*4+5"); 

  for(int i = 0; i < result.size(); i++){
    if(i == (result.size() - 1)){
      cout << result[i] << endl; 
      break; 
    }
    cout << result[i] << ", "; 
  }
//this gives the original input 
  cout << endl; 
  

  //add more test cases if needed

  string expression; 
  cout << "Enter an expression: "; 
  getline(cin, expression); 

  result = split(expression); 
  
  for(int i = 0; i < result.size(); i++){
      cout << result[i] << endl;  
  }
  //this gives the multiline output
  return 0;
}
