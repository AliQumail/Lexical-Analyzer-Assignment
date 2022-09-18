#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fstream>

using namespace std;

string myText[100] = {};
string* tokens;
ofstream out_file;

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

void check_valid_comment(){

}

void check_valid_identifier(){

}

void check_valid_string(){

}
int check_valid_assignment_op(string t){
    if (t == "="){
       out_file.open ("tokens.txt",ios::app);
       out_file << "(AsOp, " + t + ")";
       out_file.close();
       return 1;
    } 
    return 0;
}

int check_valid_keyword(string t){
   // returning 1 means true and 0 means false
   if (t == "int" || t == "if" || t == "else" || t == "do" || t == "until"
    || t == "then" || t == "read" || t == "display" || t == "displayline" || t == "return" ||
    t == "function" ){
        out_file.open ("tokens.txt",ios::app);
        out_file << "(KEY, " + t + ")";
        out_file.close();
        return 1;
   } 
   return 0;
}

int check_valid_number(string t){
    for (int i =0; i<t.size(); i++){
        
        if ( t[i] == '0' || t[i] == '1' || t[i] == '2' || t[i] == '3' 
        || t[i] == '4' || t[i] == '5' || t[i] == '6' || t[i] == '7' || 
         t[i] == '8' ||  t[i] == '9'){
           continue; 
        } else {
            return 0;
        }
    }
    out_file.open ("tokens.txt",ios::app);
    out_file << "(NUM, " + t + ")";
    out_file.close();
    return 1;
}

int main()
{
   // read file from texts
   // stores it into a string of array to make tokens
   tokens = tokenize_file_to_string();
   
   // Output tokens
   cout << "Tokens generated "<<endl;
   for (int i = 0 ; i< 10; i++){
       if (tokens[i] == "" ) break;
       cout<<tokens[i]<<", ";
    }

    cout<<endl<<endl;


    for (int i = 0; i<100 ; i++){
        if(tokens[i] == "") break;
        // check if keyword
        int is_keyword = check_valid_keyword(tokens[i]);
        if (is_keyword){
            cout<<tokens[i]<<" is a keyword"<<endl;
        } else {
            // check if assignment operator
            int is_assignment_op = check_valid_assignment_op(tokens[i]);
            if (is_assignment_op) {
                cout<<tokens[i]<<" is an assignment operator"<<endl;
            } else {
                int is_number = check_valid_number(tokens[i]);
                if (is_number){
                    cout<<tokens[i]<<" is a number"<<endl;
                }
            }
        }

    }


    
   return 0;
}