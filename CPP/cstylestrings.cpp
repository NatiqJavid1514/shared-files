#include <iostream>
#include <cstring>
#include <cctype>


using namespace std;

int main(){
    
    char first_name[30] {};
    char last_name[20] {};
    char full_name[50] {};
    char temp[50] {};

    // cout<<first_name<<endl;

    // cout<<"Enter your first name: "<<endl;
    // cin>>first_name;

    // cout<<"Enter you last name: "<<endl;

    // cin>>last_name;


    // cout<<"your first name has "<<strlen(first_name)<<" characters"<<endl;
    
    
    // strcpy(full_name,first_name);
    // strcat(full_name," ");
    // strcat(full_name,last_name);


    
    
    

    // cout<<full_name;

    cout<<"Enter your full name: "<<endl;
    cin.getline(full_name,50);
    // cout<<full_name<<endl; 

    strcpy(temp,full_name);

    for(size_t i{0}; i<strlen(full_name); i++){
        if(isalpha(full_name[i])){
            full_name[i]=toupper(full_name[i]);
        }
    }


    if(strcmp(full_name,temp)==0){

        cout<<"Both names are same "<<endl;
        
    }

    else{
        cout<<"Both names are differnet"<<endl;
    }
    cout<<temp<<endl;





}
