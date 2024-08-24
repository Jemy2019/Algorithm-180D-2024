#include <iostream>

using namespace std;

int arr[101],n;

void swapAB(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
  //  cout<< "inside Func" <<a<<" " <<b<<endl;
}

void printArray(){
    cout<<"Array values: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int x = 7, y = 3;
    cout<< (x && y)<<endl;
    cout<< (x & y)<< endl;

    cout<< (x || y)<<endl;
    cout<< (x | y)<< endl;

    cout<< (!x)<<endl; /// 0
    cout<< (~x)<< endl; /// -8  >>> bit (31) >> 1 negative

    cout<< (y^x)<< endl;

    cout<< (x<<y) << endl;
    cout<< (x>>y) << endl;
    
    return 0;
}


