//problem: reverse given sentence string (with spaces)

//language: c++

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm> //fixed reverse scope problmm

using namespace std;

string reverseWords(const string &sentence) {

    istringstream iss(sentence); //input stream
    vector<string> words;
    string word;

    while(iss >> word) { //reading the sentence, separate words
        words.push_back(word); //seprate
    }

    reverse(words.begin(), words.end());

    ostringstream oss; //output stream for reverse string

    for(size_t i = 0; i < words.size(); i++ ) {
        if(i > 0) oss << " "; //put space back
        oss << words[i]; //print reversed words.
    }

    return oss.str();

}

int main() {

    string sentence = "sphinx of black quartz judge my vow";
    cout << reverseWords(sentence) << endl;  // we want the words to show "vow my judge quartz black of sphinx"
    return 0;
}