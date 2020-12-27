/* Noor is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line
and each of them has a score according to performance. Noor wants to give at least 1 chocolate to each student.
She distributes chocolates to them such that If two students sit next to each other then the one with the higher score
must get more chocolates. Noor wants to save money, so she wants to minimise the total number of chocolates.
Note that when two students have equal score they are allowed to have different number of chocolates. */

#include <iostream>
#include <stdio.h>
using namespace std;

int getMin(int *arr, int n){
   /* Don't write main().
      Don't read input, it is passed as function argument.
      Return output and don't print it.
      Taking input and printing output is handled automatically.
   */

    int* chocolates = new int[n];
    chocolates[0] = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i] > arr[i-1])
            chocolates[i] = 1 + chocolates[i-1];
        else
            chocolates[i] = 1;
    }

    for(int i=n-2;i>=0;i--)
    {
        if(arr[i] > arr[i+1] && chocolates[i] <= chocolates[i+1])
            chocolates[i] = 1 + chocolates[i+1];
    }

    int s = 0;
    for(int i=0;i<n;i++)
        s += chocolates[i];

    return s;
}

int main(){

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << getMin(arr, n);
    delete []arr;
}
