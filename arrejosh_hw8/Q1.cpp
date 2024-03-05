#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

// Include other libraries as needed
//


using namespace std;

string reverseString(const string &s1) {
  // Write your reverseString function here
  int size = s1.length();

  if(size >= 15){
      throw 500;
  }

  string rs1 = s1;
  reverse(rs1.begin(), rs1.end()); //reverses string in algorithm library

  return rs1;
}

int main() {
    int lineNo = 0;
  // Write your program here
  // Include following message for error handling:
  // cout << "Error: line " << lineNo << " exceeds 15 characters, skipping\n";
  //
  //
  //

    ifstream ifile("words.txt");
    ofstream ofile("reversewords.txt"); //creating the reversed output file for words.txt

    if(!ifile.is_open()){
          cerr << "ifile didn't open! \n";
          return 1;
    }

    if(!ofile.is_open()){
          cerr << "ofile didn't open! \n";
        return 1;
    }


    string line;
        while(getline(ifile, line)){
            lineNo++;
            try{
                if(!line.empty()){
                    line = reverseString(line);
                    ofile << line << endl;
                }
            }
            catch (int e) {
                cout << "Error: line " << lineNo << ": exceeds 15 characters, skipping\n";
                //if the try and catch isn't in the while loop it'll stop at the error
            }

    }


    ifile.close();
    ofile.close();

     return 0;
}
