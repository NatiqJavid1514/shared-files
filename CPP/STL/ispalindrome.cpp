#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
void display(deque <char> &d){
    for(auto c:d){
        cout<<c;
    }
    cout<<endl;
}
bool ispalindrome(deque <char> &d){
    auto it=d.begin();
    auto it2=d.end()-1;
    
    while(it<it2){
        if(*it!=*it2){
            return false;
            

        }
        else{
            it++;
            it2--;

        }
    }
    return true;

    


}




int main(){
    string s;
    deque <char> pal;
    cout<<boolalpha;
    cout<<"Enter your word: ";
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
     pal.push_back(s[i]);}
    }
    display(pal);
    
    cout<<ispalindrome(pal);

}