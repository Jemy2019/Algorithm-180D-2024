#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    cout<<"Array values: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/// O(szA+ szB) => O(n)
void simpleMerge3(int arr[], int l, int m, int h) {
    int szA = m-l+1;
    int szB = h-m;

    int C[szA + szB];
    int i,j,k=0;
    i=l;
    j=m+1;

    while (i<szA && j<szB) {
        if (arr[i] < arr[j]) C[k++] = arr[i++];
        else C[k++] = arr[j++];
    }

    while (i<szA) C[k++] = arr[i++];

    while (j<szB) C[k++] = arr[j++];

    k=0;    
    for (int x = l; x <= h; x++){
       arr[x] = C[k++];
    }
}

/// O(nlogn)
void MS (int arr[], int l, int h) {
    if (l<h) {
        int mid = (l+h)/2; /// 0 /// 1 7
        MS(arr, l, mid); /// left 1 7
        MS(arr, mid+1, h); /// right 3 5
        simpleMerge3(arr, l, mid, h);
    }

}

int main()
{

    int arr[]={3,7,10,11,5,7,9},n=7;

    int A[]={3,7,10,11},B[]={5,7,9};
    simpleMerge(A, 4, B, 3);


    MS(arr, 0, n-1);
    cout<<"After Merge sort: ";
    printArray(arr, n);
    return 0;
}
