#include<iostream>
using namespace std;
main()
{
	int a[100],i,n,mid,high,low,key,found=0;
	cout<<"Enter the number of elements \n";
	cin>>n;
	cout<<"Enter the elements of array in ascending order \n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the key element \n";
	cin>>key;
	low=0;
	high=n-1;
	while(low<=high && !found)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
		found=1;
		else if(a[mid]<key)
		low=mid+1;
		else
		high=mid-1;
	}
	 if (found==1)
	 {
	 	if(mid+1==1)
	 	{
	 		cout<<"Element is found at "<<mid+1<<"st position \n";
		 }
		 else if(mid+1==2)
		 {
		 	cout<<"Element is found at "<<mid+1<<"nd position \n";
		 }
		 else if(mid+1==3)
		 {
		 	cout<<"Element is found at "<<mid+1<<"rd position \n";
		 }
		 else 
		 cout<<"Element is found at "<<mid+1<<"th position \n";
	 }
	 else 
	 cout<<"Not found \n";
	
		
	}

