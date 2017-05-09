#include <iostream>

using namespace std;

int A[8] = {2,8,7,1,3,5,6,4};

int partition(int array[], int left ,int right);
void quickSort(int array[], int left, int right)
{
    int position;
    if ( left < right )
    {
        position = partition(array, left, right);
        quickSort(array,left,position-1); 
        quickSort(array, position+1, right);   
    }
}

int partition(int array[], int left ,int right)
{
    int base = array[left];
    while(left < right){
      while((left < right)&& array[right] >= base)
      {
	right--;   
      }
      if(array[right] < base)
      {
	array[left++] = array[right];
      }
      while((left < right) && array[left] < base){
        left++;
      }
      if(array[left] >= base){
        array[right--] = array[left];
      }
    }
    array[left] = base;
    return left;
}

int main(int argc, char **argv)
{
    int i;
    for (i=0;i<8;i++)
    {
        cout<<"A["<<i<<"]="<<A[i]<<" "; 
    }
    quickSort(A, 0, 7);
    cout<<"\n"<<"after quick sort!"<<endl;
    for (i=0;i<8;i++)
    {
        cout<<"A["<<i<<"]="<<A[i]<<" "; 
    }
    cout<<endl;
    return 1;
}
