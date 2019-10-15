#include<stdio.h>
int partition(long array[],int start,int end)
{	
	int pivot,partitionindex,i;
	long temp;
	pivot = array[end];  //pivot is taken to be the last element of the array//
	partitionindex = start;//partition index be the first index of the array//
	i = start;
	while(i<end)//Initialising a loop from start to end of the array//
	{
		if(array[i]<pivot)//If the element of the array is less than the pivot//
		{
			temp = array[partitionindex];//swap the element and the element at the partition index//
			array[partitionindex]=array[i];
			array[i] = temp;
			partitionindex++;
		}
		i++;
	}
	temp = array[end];//swap the pivot and the element at the partition index//
	array[end] = array[partitionindex];
	array[partitionindex] = temp;
	return partitionindex;
}	
void quicksort(long array[],int start,int end)
{
	int i,n,k;
	if(start<end)
	{
                int partitionindex = partition(array,start,end);//partition brings the pivot to the correct place//
		quicksort(array,start,partitionindex-1);//quicksort function for the array to the left of pivot element//
                quicksort(array,partitionindex+1,end);//quicksort function for the array to the right of pivot element//
	}

}	
	
int main()
{	
	int n,i,k;
	scanf("%d",&n);	
	long array[n];
	for(i = 0;i<n;i++)
	{
		scanf("%ld,",&array[i]);//Taking the values for the array//
	}
	k = partition(array,0,n-1);
	quicksort(array,0,n-1);//quicksort function for the array//
	for(i =0;i<n;i++)
        {
                printf("%ld ",array[i]);//print the elements in the array//
        }
        printf("\n%d",k);


}	
	
