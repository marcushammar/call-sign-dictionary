#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    string dictionary, dictionaryRowString, prefix;
    int length;
    char dictionaryRowChar[100];
    
    cout << "What dictionary file would you like to use?" << endl;
    cin >> dictionary;
    cout << "What call sign prefix would you like?" << endl;
    cin >> prefix;
    cout << "How long should the call sign be?" << endl;
    cin >> length;
    cout << "You want to generate a call sign from the file " << dictionary << " that is " << length << " characters long and has the prefix " << prefix << "." << endl;
    
    transform(prefix.begin(), prefix.end(), prefix.begin(), ::toupper);
    
    ifstream file(dictionary);
    while(file.getline(dictionaryRowChar, 100)){
        dictionaryRowString = string (dictionaryRowChar);
        if (dictionaryRowString.length() == length){
            transform(dictionaryRowString.begin(), dictionaryRowString.end(), dictionaryRowString.begin(), ::toupper);
            if (dictionaryRowString.substr(0, prefix.length()) == prefix){
                cout << dictionaryRowString << endl;
            }
        }
    }
    
    return 0;
}
