#include <iostream>

using namespace std;
int n, arr[101], frq[101], pre[101], kad[101];



void printArray(int arr[], int n){
    cout<<"Array values: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    
    cin>>n;
    for (int i =0; i<n;i++) {
        cin>>arr[i];
    }
/// Frequency array
    for(int i=0; i<n;i++){
        frq[arr[i]]++;
    }

    printArray(frq, 101);

/// Prefix sum
    pre[0]=arr[0];
    for (int i=1; i<n; i++) {
        pre[i]=arr[i]+pre[i-1];
    }

    printArray(pre, n);

/// Kaddane
    for(int i=0; i<n; i++){
        if (i==0) kad[i]=arr[i];
        else kad[i]=arr[i]+kad[i-1];

        kad[i] = (kad[i]<0)? 0:kad[i];           
    }

    printArray(kad,n);

    return 0;

}
