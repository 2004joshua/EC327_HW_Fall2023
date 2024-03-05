#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>

// Include any additional libraries you'd like up here...
// Remember your must use map as your primary data structure!

using namespace std;

// Define any helper functions you like up here...


int main(int argc, char * argv[]) {

    int isbn;
    string title;

    // Q5a
	// Declare your map here
	map<int, string> book_catalog;
	

	// Q5b
	cout << "Type in the details for a book and hit enter to add to the catalog." << endl;
	cout << "Alternatively, type \"-1\" and hit enter to exit this program." << endl;

    do{
        cout << "Insert the book's ISBN: " << endl;
        cin >> isbn;

        if(isbn == -1){
            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Insert the book's title: " << endl;
        getline(cin, title);

        if(book_catalog.find(isbn) != book_catalog.end()){
            cout << "A book with that ISBN is already in the library!" << endl;
        } else {
            book_catalog.insert(pair<int,string>(isbn,title));
        }

    }while(isbn != -1);


	// Q5c
	// Do your file handling here!

    ofstream out("library_list.txt");

    if(!out.is_open()){
        cerr << "Failed to open file." << endl;
        return 1;
    }

    for(const auto& pair : book_catalog){
        out << pair.second << endl;
    }

    out.close();

	return 0;
}
