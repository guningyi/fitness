#include <iostream>

using namespace std;

int A[8] = {2,8,7,1,3,5,6,4};

int partition(int array[], int p ,int r);
void quickSort(int array[], int p, int r)
{
    int q;
    if ( p < r )
    {
        q = partition(array, p, r);
        cout<<"q="<<q<<endl;
        quickSort(array,p,q-1); 
        quickSort(array, q+1, r);   
    }
}

int partition(int array[], int p ,int r)
{
    int x = array[r];
    int i = p-1;
    int j;
    int temp;
    for(j=p; j<r-1;j++)
    {
        if (array[j] > x)
        {
            j++;
        }
        else if(array[j] <= x )
        {
            i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            j++;
        }
    }
    temp = x;
    //cout<<"i="<<i<<endl;
    array[r] = array[i+1];
    array[i+1] = x;
    return i+1;
}

int main(int argc, char **argv)
{
    int i;
    for (i=0;i<8;i++)
    {
        cout<<"A["<<i<<"]="<<A[i]<<" "; 
    }
    quickSort(A, 1, 7);
    cout<<"\n"<<"after quick sort!"<<endl;
    for (i=0;i<8;i++)
    {
        cout<<"A["<<i<<"]="<<A[i]<<" "; 
    }
    cout<<endl;
    return 1;
}
