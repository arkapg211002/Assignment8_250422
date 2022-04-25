/*Write a program in C to implement the following sorting techniques:

Quick Sort
*/
#include<stdio.h>
#include<stdlib.h>

int partition(int a[],int low,int high)
{
    int pivot,i,j,temp;
    pivot=a[low];
    i=low;
    j=high+1;
    do
    {
        do
        {
            i++;
        }while(a[i]<=pivot);
        do
        {
            j--;
        }while(a[j]>pivot);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
void quickSort(int a[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quickSort(a,low,j-1);
        quickSort(a,j+1,high);
    }
}
int main()
{
    int n,*p;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("The elements are: \n");
    p=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    quickSort(p,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",p[i]);
    return 0;
}

