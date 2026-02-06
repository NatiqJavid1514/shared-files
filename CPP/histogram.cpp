#include <iostream>
using namespace std;
#include <vector>

// Nested loops- Histogram//

int main(){ 

    int data_types{};

    cout<<"How many data-types do you have: "<<endl;

    cin>>data_types;
    vector <int> histogram{};

    for(int i{1};i<=data_types; i++){
        int nums{};
        cout<<"Enter data type "<<i<<" :"<<endl;
        cin>>nums;

        histogram.push_back(nums);







    }
    cout<<"\n-------------------------------------------"<<endl;
    

    for( auto val:histogram){
        for(int v{1}; v<=val; ++v){
            cout<<"*";
        }
        cout<<endl;
    }








}