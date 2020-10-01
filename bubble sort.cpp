#include<iostream>
using namespace std;
main()
{
	int n,i,j,temp,a[10];
	cout<<"Enter the number of elements \n";
	cin>>n;
	cout<<"Enter elements \n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"The original elements are \n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<"\n The sorted elements are \n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
