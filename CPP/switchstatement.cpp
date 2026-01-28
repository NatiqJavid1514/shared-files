#include <iostream>
using namespace std;

int main(){

    char grade{};

    cout<<"Enter the grade you are expecting in exams: "<<endl;

    cin>>grade;

    switch(grade){

        case 'a':
        case 'A':
        cout<<"Amazing you can keep studying hard"<<endl;
        break;

        case 'b':
        case 'B':

        cout<<"Emm great but you can do better!!!!"<<endl;
        break;

        case 'c':
        case 'C':

        cout<<"Really? You are shit kole czhotle"<<endl;

        break;

        case 'D':
        case 'd':
        
        cout<<"Hata fail guriya che lachmaya"<<endl;
        break;

        case 'F':
        case 'f':

        cout<<"Hata near saar cement kole dalle sindya czhe kaem woni parun"<<endl;

        break;

        
        default:

        cout<<"Hata this grade doesn't exist"<<endl;
      










    }





}