#include <bits/stdc++.h>
#define N ((int)1e3 + 1)
#define isOn(x, k) ((x>>k) & 1)

using namespace std;
//const int N = 1e3 + 1;
int arr[N],n, T, f;

void printArray(){
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
    scanf("%d%d", &n, &T);
    
    for(int i=0; i<n; i++) {
        scanf("%d", arr + i);
    }
    printArray();

    bitmask();

    if (f) puts("YES");
    else puts("NO");


    return 0;
}