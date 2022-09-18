#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fstream>

using namespace std;

string myText[100] = {};
 

string* tokenize_file_to_string(){
    ifstream file;
    file.open("text.txt");
    string x;
    int i = 0;
    while (!file.eof()) {
       file >> x;
       myText[i] = x;
       i = i + 1;
    }
    return myText;
    
}

int main()
{
   string* tokens;

   // read file from texts
   // stores it into a string of array to make tokens
   tokens = tokenize_file_to_string();
   
   // Output tokens
   cout << "Tokens generated "<<endl;
   for (int i = 0 ; i< 10; i++){
       if (tokens[i] == "" ) break;
       cout<<tokens[i]<<", ";
    }

    cout<<tokens[0].size();

   return 0;
}