//question: best data struct for phone books with names + numbers

//answer: hashmap

//coded example

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {

    unordered_map<string, string> phoneBook;

    //add numbers + names
    phoneBook["Kunal"] = "555-1234";
    phoneBook["Tushar"] = "555-5678";
    phoneBook["Samheart"] = "555-8765";
    phoneBook["FalakPaneer"] = "555-2345";
    phoneBook["RAM"] = "555-3288";

    //look up number
    string name = "RAM";
    if(phoneBook.find(name) != phoneBook.end())
        cout << name << "'s phone number is: " << phoneBook[name] << endl;
    else
        cout << name << " not found in the phone book." << endl;

}