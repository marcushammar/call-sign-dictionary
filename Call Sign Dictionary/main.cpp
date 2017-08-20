#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    string dictionary, prefix;
    int length;
    char dictionaryRow[100];
    
    cout << "What dictionary file would you like to use?" << endl;
    cin >> dictionary;
    cout << "What call sign prefix would you like?" << endl;
    cin >> prefix;
    cout << "How long should the call sign be?" << endl;
    cin >> length;
    cout << "You want to generate a call sign from the file " << dictionary << " that is " << length << " characters long and has the prefix " << prefix << "." << endl;
    
    ifstream file(dictionary);
    while(file.getline(dictionaryRow, 100)){
        if (dictionaryRow[length] == '\0'){
            if (string(dictionaryRow).substr(0,prefix.length()) == prefix){
                cout << dictionaryRow << endl;
            }
        }
    }
    
    return 0;
}
