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

int check_block_start(string t){
    if (t == "{") {
      out_file.open ("tokens.txt",ios::app);
      out_file << "(Blo, " + t + ")";
      out_file.close();
      return 1;
    }
    return 0;
}
int check_block_end(string t){
    if (t=="}") {
      out_file.open ("tokens.txt",ios::app);
      out_file << "(Blo, " + t + ")";
      out_file.close();
      return 1;
    }
    return 0;
}


int check_valid_comment(string t){
  if ( t == "#~" || t == "~#" ){
      out_file.open ("tokens.txt",ios::app);
      out_file << "(Com, " + t + ")";
      out_file.close();
      return 1;
  } else {
    return 0;
  }
}

int check_valid_relational_op(string t){
     if (t == "-eq" || t == "-ne" || t == "-lt" || t == "-le" || t == "-gt"
      || t == "-ge" ){
        out_file.open ("tokens.txt",ios::app);
        out_file << "(RelOp, " + t + ")";
        out_file.close();
        return 1;
    } 
    return 0;

}



int check_valid_identifier(string t){

    int i=0;

    if (t[0] == '$') {



      for (int i =1; i<t.size(); i++)

      {

            if ( t[i] == '0' || t[i] == '1' || t[i] == '2' || t[i] == '3' 

            || t[i] == '4' || t[i] == '5' || t[i] == '6' || t[i] == '7' || 

            t[i] == '8' ||  t[i] == '9' || t[i] == 'a' || 

            t[i] == 'a' || t[i] == 'b' || t[i] == 'c' || t[i] == 'd' || t[i] == 'e' || 

            t[i] == 'f' || t[i] == 'g' || t[i] == 'h' || t[i] == 'i' || t[i] == 'j' || t[i] == 'k' || t[i] == 'l' || t[i] == 'm' || 

            t[i] == 'n' || t[i] == 'o' || t[i] == 'p' || t[i] == 'q' || t[i] == 'r' || t[i] == 's' || t[i] == 't' || t[i] == 'u' || 

            t[i] == 'v' || t[i] == 'w' || t[i] == 'x' || t[i] == 'y' || t[i] == 'z' || 

            t[i] == '_' || t[i] == '-' ){

            continue; 

            } else {

                return 0;

            }

      }

   

    out_file.open ("tokens.txt",ios::app);

    out_file << "(ID, " + t + ")";

    out_file.close();

    return 1;
     } else {
        return 0;
     }



}



int check_valid_string(string t){

   for (int i = 0; i<t.size() ; i++){
     if ((t[i] >= 65 && t[i] <= 90) || (t[i]>=97 && t[i]<=122)){
        continue;
     } else {
        return 0;
     }
   }
   out_file.open ("tokens.txt",ios::app);
   out_file << "(STR, " + t + ")";
   out_file.close();
   return 1;

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

int check_valid_arithematic_op(string t){
    if (t == "+" || t == "-" || t == "/" || t == "%" || t == "*"){
        out_file.open ("tokens.txt",ios::app);
        out_file << "(AriOp, " + t + ")";
        out_file.close();
        return 1;
    } 
    return 0;
}

int check_valid_special_char(string t){
    if (t == "," || t == ":" || t == ";" || t == "(" || t == ")" || t == "$"){
        out_file.open ("tokens.txt",ios::app);
        out_file << "(SpChar, " + t + ")";
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

        // check if variable

        int is_variable = check_valid_identifier(tokens[i]);

        if (is_variable){

            cout<<tokens[i]<<" is a variable"<<endl;

        } else {

            // check for key word

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

                    } else {
                        int is_string = check_valid_string(tokens[i]);
                        if (is_string){
                             cout<<tokens[i]<<" is a string"<<endl;
                        } else {
                            int is_comment = check_valid_comment(tokens[i]);
                            if (is_comment) {
                                cout<<tokens[i]<<" is a comment"<<endl;
                            } else {
                                int is_block_start = check_block_start(tokens[i]);
                                if (is_block_start){
                                    cout<<tokens[i]<<" is a block start"<<endl;
                                } else {
                                    int is_block_end = check_block_end(tokens[i]);
                                    if (is_block_end){
                                        cout<<tokens[i]<<" is a block end"<<endl;
                                    } else {
                                        int is_arith_op = check_valid_arithematic_op(tokens[i]);
                                        if (is_arith_op){
                                            cout<<tokens[i]<<" is a arithematic operator"<<endl;
                                        } else {
                                            int is_special_char = check_valid_special_char(tokens[i]);
                                            if (is_special_char){
                                                cout<<tokens[i]<<" is a special character"<<endl;
                                            } else {
                                                int is_relational_op = check_valid_relational_op(tokens[i]);
                                                if (is_relational_op){
                                                    cout<<tokens[i]<<" is a relational op"<<endl;
                                                }
                                            }

                                        }
                                    }

                                }
                            }
                        }
                    }

                }

            }



        }



    }

    

   return 0;

}
