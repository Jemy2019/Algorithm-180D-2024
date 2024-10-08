/*
  180 Daraga Training
  Session No : 1
  Session : Time Complexity analysis
  By : Muhammad Magdi
  On : 20/08/2017
*/

/// prime number example
* What's time Complexity?
    How does the running time change as the size of input change.
    Rate of change of time with respect to size of input.

* Running time depends on:
    1- Processor.
    2- Read/Write speed to memory.
    3- 32 bit VS 64 bit.
    4- INPUT.
    5- ...

* What are the cases your code may face?
    1- Best case.
    2- Worst case.
    3- Average case.

* The notations to represent your code's Complexity:
    1- Big O Notation     ---->     the upper bound of the time.
    2- Omega Notation     ---->     the lower bound of the time.
    3- Theta Notation     ---->     the bound itself.

* Rules:
    1- Running time is the sum of running times of all consecutive blocks.
    2- Nested loops are multiplied.
        In general -> Nested repetitive Blocks are multiplied.
    3- In Conditional statements pick the "Worst case" one.
    4- Drop Constants (addition, subtraction, multiplication or division).
    5- Drop all lower order terms.


* Some useful Observations:
  Big O                 Name                    Max n
-------------------------------------------------------------------------------------------
  O(1)        ---->     Constant      ---->     1e18      ---->     Math, Observation
  O(Log(n))   ---->     Logarithmic   ---->     1e18      ---->     Binary Search (lower -upper- bound)
  O(n)        ---->     Linear        ---->     1e8       ---->     one loop
  O(n*Log(n)) ---->     LogLinear     ---->     4e6       ---->     Sorting, loop + binary search
  O(n^2)      ---->     Quadratic     ---->     1e4       ---->     nested loop
  O(2^n)      ---->     Exponential   ---->     25        ---->     Bitmasks, finding all possible answers
  O(n!)       ---->     factorial     ---->     11       ---->     finding all permutations


int calcSum(int a, int b){		                //O(1)
  int sum = a+b;
  return sum;
}





double calcAverage(int a, int b, int c){		         //O(1)
  double avg = (a+b+c)/3.0;
  return avg;
}




bool isAlphabit(char x){		                //O(1)
  return (x>='A' && x<='Z' || x>='a' && x<='z');
}



double sumHarmonicSeries(int n){	            	//O(n)
  double sum = 0;

  for(int i = 1 ; i <= n ; ++i){
    sum += (1.0/i);
  }
  return sum;
}






long long calcSumSegment(int a, int b){	      	//O(b)
  /// 0=< a,b =<10^6
  long long sum = 0;
  for(int i =a ; i<=b ; ++i)
    sum += i;
  return sum;
}






int stepper(int n, int s){                      //O(n/s) => O(n)
  int ret = 0;
  /// 1<n<10^6 , 1<s<10^6
  for(int i = 1 ; i <= n ; i += 1){
    ret += i;
  }
  return ret;
}






/// problem merge 2-arrays
void merge(int* A, int szA, int* B, int szB){   //O(sz)
  int idxA = 0, idxB = 0, idxC = 0;
  while(idxA < szA && idxB < szB){
    if(A[idxA] < B[idxB]) C[idxC++] = A[idxA++];
    else C[idxC++] = B[idxB++];
  }

  while(idxA < szA) C[idxC++] = A[idxA++];
  while(idxB < szB) C[idxC++] = B[idxB++];
}





int fact(int n){		//O(n)
  if(n==0 || n==1)	return 1;
  return n*fact(n-1);
}
/// fact(7) >>720
/// 7! = 7*6!
/// 6! = 6*5!
/// 5! = 5*4!
/// 4! = 4*3!
/// 3! = 3*2!
/// 2! = 2*1!
/// 1! = 1   || 0! = 1


int power1(int base, int power){		        //O(power)
  if(power==1)  return base;
  return base*power1(base, power-1);
}




void calArrayLog(){
    for(int i=0;i<n;i++){
        calcLog(arr[i]);
    }
}






int calcLog(int n){	               	            //O(log(n))
  int ret = 0;
    while(n > 1){
    ++ret;/// 5
    n /= 2; /// 1
  }
  return ret;
}
/// n = 32 >> 16 >> 8 >> 4 >> 2 >> 1





bool binarySearch(int val, int n){			//O(log(n))
  int lo = 0, hi = n, mid;
  while(hi-lo > 0){
    mid = ((lo+hi)/2);
    if(A[mid] == val) return 1;
    if(A[mid] < val)
      lo = mid+1;
    else
      hi = mid-1;
  }
  return 0;
}

void printPowersOfTwoTill(int n){               //O(log(n))
  for(int p = 1 ; p <= n ; p *= 2)
    printf("%d\n", p);
}
/*
int power2(int base, int power){		//O(log(n))
  if(!power)  return 1;
  int sub = power2(base, power>>1);
  return (power&1? sub*sub*base : sub*sub);
}
*/
/*
for(int i = 0 ; i < (1<<n) ; ++i){		//O(2^n)
  //some O(1) operations
}
*/
/*
8 4 2 1
0 0 0 1
0 0 1 0
0 1 0 0
1 0 0 0

1<<0 = 2^0 = 1
1<<1 = 2^1 = 2
1<<2 = 2^2 = 4
1<<n = 2^n
*/

int fib(int n){		                            //O(2^n)
  if(!n || n==1)	return n;
  return fib(n-1)+fib(n-2);
}


/*
for(int i = 0 ; i < (1<<n) ; ++i){		//O(n * (2^n))
  for(int i = 0 ; i < n ; ++i){
    //some constant order statements go here
  }
}
*/

void searchArray(){		                        //O(n*log(n))
  for(int i = 0 ; i < n ; ++i){
    if(binarySearch(B[i]))
      puts("Found");
    else
      puts("Not Found");
  }
}

void something(int n){		//O(n*log(n))
  for(int i = 1 ; i <= n ; ++i)
    for(int j = i ; j <= n ; j+=i)
      //Something
}
/*
void mergeSort(int st = 0, int en = n-1){   //O(n*log(n))
  if(st == en)  return;
  int mid = (st+en)>>1;
  mergeSort(st, mid);
  mergeSort(mid+1, en);
  merge(A, mid-st+1, A+mid+1, en-mid);
}
*/

void printPermutations(string s){		        //O(n!)
  sort(s.begin(), s.end());
	do {
		cout << s << endl;
	}while(next_permutation(s.begin(), s.end()));
}
