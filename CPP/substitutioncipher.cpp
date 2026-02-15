#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

int main(){
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    char selection{};

    do{
        cout<<"1. Encypt a word"<<endl;
        cout<<"2. Decypt a word"<<endl;
        cout<<"3. Quit"<<endl;

        cout<<"\nEnter your Selection-------------------------------------------------"<<endl;

        cin>>selection;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       
        string word{};
        size_t position{};

        if(selection=='1'){

            

          cout<<"Enter the word you want to Encrypt: "<<endl;
          getline(cin,word);

          vector <size_t> uwu{};
          
          for(size_t i{0};i<word.length();i++){
            size_t position=alphabet.find(word[i]);

            uwu.push_back(position);
        };
          
          for(size_t p{0};p<uwu.size();p++){
            
            if(uwu.at(p) != string::npos)
            word[p]=key[uwu.at(p)];

            

          };

          cout<<"Your decrypted code is: "<<word<<endl;
            
          
        }

        else if(selection=='2'){
            cout<<"Enter the word you want to decypt: "<<endl;
          getline(cin,word);

          vector <size_t> uwu{};
          
          for(size_t i{0};i<word.length();i++){
            size_t position=alphabet.find(word[i]);

            uwu.push_back(position);
        };
          
          for(size_t p{0};p<uwu.size();p++){
            if(uwu.at(p) != string::npos)

            word[p]=alphabet[uwu.at(p)];

            

          };
          cout<<"Your encrypted code is: "<<word<<endl;








        }
        else if(selection=='3'){
            cout<<"Sayonara"<<endl;

        }

        else{
            cout<<" Invalid Input! Please try again"<<endl;
        }

    }while(selection!='3');
}