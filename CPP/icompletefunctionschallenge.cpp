#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void print_numbers(vector<int> &v);
void print_numbers(vector<int> &v){
    if(v.size()==0){
        cout<< " There are no numbers in the database"<<endl;
    }

    else{
        cout<<"[ ";
        for(auto s:v){
            cout<<s;
            cout<<" ";
        }
        cout<<" ]";
        cout<<endl;
    }
};
void add_number(vector<int> &v);
void add_number(vector<int> &v,int num_to_add){

    v.push_back(num_to_add);

    

}

void find_the_number(int num2){
int num2{};
cout<<"Enter the number you want to find: ";
cin>>num2;




}
void find(vector<int>, int num2)











int main(){

    char selection {};
    vector <int> numbers{};
    int num1{};

    do{

    cout<<"P - Print numbers"<<endl;
    cout<<"A - Add a number"<<endl;
    cout<<"M - display mean of numbers"<<endl;
    cout<<"S - Smallest of all numbers"<<endl;
    cout<<"L - Largest of all numbers"<<endl;
    cout<<"Q - Quit"<<endl;

    cout<<"\n------------------------------"<<endl;

    cout<<"Enter your selection: "<<endl;
    cin>>selection;

    switch(selection){
        case 'p':
        case 'P': 
        print_numbers(numbers);
        break;
        case 'a':
        case 'A':
        cout<<"Enter the number you want to add to the database: ";
        cin>>num1;
        add_number(numbers,num1);
    };

    
}
while(selection!='Q'&& selection!='q');




}