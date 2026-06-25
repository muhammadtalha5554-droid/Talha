#include <iostream>
using namespace std;
int main()
{
   int a=2;
    int b=5;
    cout<<"Before swapping: "<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    a=a-b;
    b=a+b;
    a=b-a;
    cout<<"After swapping: "<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;  
return 0;
}