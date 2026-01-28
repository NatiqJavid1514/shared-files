#include <iostream>
using namespace std;
//shipping cost calculator
/*Ask the user for package dimension in inches
length,width and height should be in Integers
All dimensions should be 10 inches or less or We cannot ship it 

Base Cost $2.50
If package volume is greater than 100 cubic inches there is a 10% surcharge
If package volume is greater than 500 cubic inches there is a 25% surcharge


*/

int main(){

    int length{},width{},height{};
    double base_cost{2.50};
    int max_dimension_length{10};

    int package_volume{};
    int threshold_volume1{};
    int threshold_volume2{};

    double surcharge1{0.1};
    double surcharge2{0.25};





    cout<<"Welcome to nats shipping & co."<<endl;
    cout<<"Please enter the details of the shipping package below"<<endl;



    cout<<"Enter the length of package: "<<endl;
    cin>>length;
    


    cout<<"Enter the width of package"<<endl;
    cin>>width;

    cout<<"Enter the height of package"<<endl;
    cin>>height;

    package_volume=length*width*height;

    if(length<=max_dimension_length&&width<=max_dimension_length&&height<=max_dimension_length){

        if(package_volume<threshold_volume1){

            cout<<"The volume of package is: "<<package_volume<<endl;

            cout<<"Your Package will be delivered"<<endl;
            cout<<"Total cost of your delivery will be $ "<<base_cost<<endl;

            
            
            


        }
        else if(package_volume>threshold_volume1&&package_volume<threshold_volume2){

            cout<<"The volume of package is: "<<package_volume<<endl;
            
            cout<<" Your package will be delivered"<<endl;

            cout<<"As your package exceeds the max volume for base cost. Your total cost will include  base cost + surplus charge"<<endl;

            cout<<"Base cost: "<<base_cost<<endl;
            cout<<"Surplus charge: "<<base_cost*surcharge1<<endl;
            cout<<"Total cost: "<<base_cost+(base_cost*surcharge1)<<endl;







        }

        else{
            cout<<"The volume of package is: "<<package_volume<<endl;

            cout<<" Your package will be delivered"<<endl;

            cout<<"As your package exceeds the max volume for base cost. Your total cost will include  base cost + surplus charge"<<endl;

            cout<<"Base cost: "<<base_cost<<endl;
            cout<<"Surplus charge: "<<base_cost*surcharge2<<endl;
            cout<<"Total cost: "<<base_cost+(base_cost*surcharge2)<<endl;










        }



        










    }
    else{

        cout<<"your package can't be delivered as dimensions of the package exceed the limit of "<<max_dimension_length<<" inches"<<endl;



    }
    

    
    





}