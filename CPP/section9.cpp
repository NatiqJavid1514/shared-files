#include <iostream>
#include <vector>



using namespace std;


int main(){
    char selection{};
     vector <int> nums{};

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

    
   

    if(selection=='P'||selection=='p'){

        
        if(nums.empty()){
            
            cout<<"[ ] this list is empty "<<endl; }
        
        
        else{
            cout<<"[ ";
            for (auto num:nums)
            
            cout<<num<<" ";

            cout<<"]";

        }
    
    }

    else if(selection=='A'|| selection=='a'){
        int addnum{};

        cout<<"Enter the number you want to add: "<<endl;
        cin>>addnum;
        nums.push_back(addnum);

        cout<<addnum<<" added to the list"<<endl;
}

else if(selection=='M'||selection=='m'){
    double mean{};
    int sum1{};

    for(auto sum:nums){
        sum1+=sum;
        
        
        
    }
    mean=static_cast<double>(sum1)/nums.size();
    cout<<"The mean of the numbers is: "<<mean<<endl;


}

else if(selection=='S'||selection=='s'){
    int min{nums[0]};
   for(int z{0}; z<nums.size(); ++z){
    if(nums[z]<min){

        min=nums[z];
        
    }

   }
       cout<<min;
    


}

else if(selection=='L'||selection=='l'){
    int max{nums[0]};
   for(int z{0}; z<nums.size(); ++z){
    if(nums[z]>max){

        max=nums[z];
        
    }

   }
       cout<<max;



    


}

else if(selection=='q'||selection=='Q'){
    cout<<"SAYONARA"<<endl;
    break;
}

else{

    cout<<"invalid output, please try again!!"<<endl;
    
}



cout<<"\n------------------------------"<<endl;


    
}while(selection!='q'&& selection!='Q');
 
}