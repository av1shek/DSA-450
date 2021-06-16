#include<bits/stdc++.h>
using namespace std;


void push(int H[], int &size, int data, int max_size)
{
    if(size >= max_size)
    {
        cout<<"Max limit reached "<<endl;
        return;
    }
    H[size] = data;
    int temp = size;

    while( (temp-1)/2 >= 0)
    {
        if(H[temp] < H[(temp-1)/2])
            swap(H[temp], H[(temp-1)/2]);
        else
            break;
        temp = (temp-1)/2;
    }
    size++;
    return;
}



int pop(int H[], int &size)
{
    if(size<=0)
    {
        cout<<"Empty"<<endl;
        return INT_MAX;
    }
    int temp = H[0];
    size--;
    H[0] = H[size];

    int i = 0;
    while( (2*i +2 < size ) || (2*i+1 < size) )
    {
        int j;
        if( 2*i+2 >= size)
            j = 2*i +1;
        else
            j = ( H[2*i +1] > H[2*i +2 ] ? (2*i+2) : (2*i+1) );
        if(H[i]>H[j])
            swap(H[i], H[j]);
        else
            break;
        i = j;
    }
    return temp;
}


int main()
{
    int arr[] = {12, 7, 8, 5, 2, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int Heap[n+1], size = 0;
    for(int i=0;i<n;i++) push(Heap, size, arr[i], n);
    while(size!=0) cout << pop(Heap, size) << " ";
    return 0;
}

