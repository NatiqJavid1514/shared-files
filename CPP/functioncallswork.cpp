#include <iostream>
#include <vector>
#include <string>

using namespace std;

void func1(int &x,int y,int z){
    x+=y+z;
}
int func2(int a, int b){
    int result{};
    result=a+b;
    func1(result,a,b);
    return result;
}

int main(){

    int x{10};
    int y{20};
    int z{};
    z=func2(x,y);

    cout<<z<<endl;
    return 0;

}




