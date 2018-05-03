#include<iostream>
using namespace std;
int count=0;
void MaxHeapify(int A[],int size,int i)
{
	int l=(2*i)+1,r=(2*i)+2,largest,temp;
	if(l<size && A[l]>A[i])
	{	largest=l;}
	else
		largest=i;
	if(l<size)
		count++;
	if(r<size&& A[r]>A[largest])
	{	largest=r;}
	if(r<size) count++;
	if(largest!=i)
	{
		temp=A[i];
		A[i]=A[largest];
		A[largest]=temp;
		MaxHeapify(A,size,largest);
	}
}
	
void BuildMaxHeap(int A[],int size)
{
	for(int i=size/2 -1;i>=0;i--)
		MaxHeapify(A,size,i);
}

void Heapsort(int A[],int size)
{
	int temp;	
	BuildMaxHeap(A,size);
	for(int i=size-1;i>=0;i--)
	{
		temp=A[0];
		A[0]=A[i];
		A[i]=temp;
		size=size-1;
		MaxHeapify(A,i,0);
	}
}

int main()
{
	int arr[9]={5,13,2,25,7,17,20,8,4};

	Heapsort(arr,9);
	
	cout<<"Sorted array = "<<"\n";
	for(int i=0;i<9;i++)
		cout<<arr[i]<<"  ";
	cout<<"\n";
	cout<<"No. of comparisons="<<count<<"\n";
	return 0;
}
	
