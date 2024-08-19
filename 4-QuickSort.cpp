#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    cout<<"Array values: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void partition(int arr[], int i, int j) {
    int pivit = arr[i];

    while(i<j){
        if (arr[i]> arr[j]){
            swapAB(arr[i], arr[j]);
        }

        if (pivit == arr[j])i++;
        else j--;
    }    
    return i;
}

void QS (int arr[], int l, int h) {
    if (l<h){
        int pi= partition(arr, l, h);
        QS(arr, l, pi-1);
        QS(arr, pi+1, h);
    }
}



int main()
{
    int arr[]={3,7,10,11,5,7,9},n=7;

    QS(arr, 0, n-1);
    cout<<"After Quick Sort: ";
    printArray(arr, n);
    return 0;
}
