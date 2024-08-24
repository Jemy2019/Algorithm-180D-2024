#include <bits/stdc++.h>
#define N ((int)1e3 + 1)
#define isOn(x, k) ((x>>k) & 1)

using namespace std;
//const int N = 1e3 + 1;
int arr[N],n, T, f;
int frq[N], pre[N];

void printArray(int arr[], int n){
    cout<<"Array values: ";
    for(int i=0;i<n;i++){
        //cout<<arr[i]<<" ";
        printf("%d ", arr[i]);
    }
    //cout<<endl;
    puts("");
}

void bitmask(){
    f=0;
    for(int mask=0; mask<(1<<n); mask++){
        int sum =0;
        for (int k=0;k<n;k++){
            if (isOn(mask, k)){
                sum+= arr[k];
            }
        }
        if (sum == T) {
            f=1;
            return;
        }
    }
}

int main()
{
    scanf("%d", &n);
    int mx=-1;
    for(int i=0; i<n; i++) {
        scanf("%d", arr + i);
        if(arr[i]>mx)
            mx = arr[i];
    }
    printArray(arr, n);
    ///arr => 1 3 6 3 4 3 4 9
    for(int i=0;i<n;i++){
        frq[arr[i]]++;
    }
    printArray(frq, mx+1);
    ///frq => 0 1 0 3 2 0 1 0 0 1
    pre[0] = frq[0]; 
    for(int i=1;i<=mx;i++){
        pre[i] = frq[i] + pre[i-1];
    }
    printArray(pre, mx+1);
    ///pre => 0 1 1 4 6 6 7 7 7 8
    int temp[N];
    for(int i=0;i<n;i++){
       int newIndex = pre[arr[i]]; 
       temp[newIndex] = arr[i];
       pre[arr[i]]--;
    }
    printArray(temp, n+1);

    for (int i=1;i<n+1;i++){
        arr[i-1]=temp[i];
    }

    printArray(arr, n);
    return 0;
}
