#include <iostream>

using namespace std;

int arr[101],n;

void printArray(){
    cout<<"Array values: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAB (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(){  // O(n^2)
    bool flag = false;
    for (int j=0; j<n; j++) {      // O(n)                                 
        flag = false;
        for (int i = 0; i<n-1-j; i++){ // O(n)
            if (arr[i] > arr[i+1]) {
                swapAB(arr[i], arr[i+1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}
void selectionSort(){  // O(n^2)
    for (int i=0; i<n; i++) { // O(n)
        int mnidx = i;
        for (int j=i; j<n; j++) {
            if (arr[mnidx] > arr[j]) {
                mnidx = j;
            }
        }

        swapAB(arr[i], arr[mnidx]);
        printArray();

    }
}


void insertionSort(){ // O(n^2)
    /// 7 7 4 8 9
    for (int i=1; i<n; i++){ //O(n)
        int cur = arr[i]; /// 2
        int j;
        for (j = i-1; j>=0; j--){ // O(n)
            if (cur < arr[j]) { 
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = cur;

    }

}

int main()
{
/*
    int x= 5; int y = 6;
    int temp = x;///5
    x = y; /// x=6
    y = temp; /// y=5
*/
/*
    int x= 5; int y = 6;
    cout<<x<<"   "<<y<<endl;
    swapAB(x,y);
    cout<<x<<"   "<<y<<endl;
*/

    cin>>n;
    for(int i=0; i<n; i++){ ///i >>  0,1,2,3,4
        cin>>arr[i];
    }
    printArray();
    //selectionSort();
    //bubbleSort();
    insertionSort();
    cout<<"After sort"<<endl;
    printArray();

    return 0;
}


