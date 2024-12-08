#include<iostream>
#include<ctime>
using namespace std;
int main()
{ int first,last,count=0;
  int A[20];
  int flag=1;
  int N,i,j,Target,temp;
  //clock_t start,end;

  cout<<"Enter the Size of Your Array: ";
  cin>>N;


for ( i = 0; i < N; i++)
{
    cout<<"Enter the "<<i+1<<" Element ";
    cin>>A[i];
}

cout<<"\nYour Array with its index is:\n";
for ( i = 0; i < N; i++)
{
    cout<<i<<"\t|";  
}
cout<<"\n";
for ( i = 0; i < N; i++)
{
    cout<<A[i]<<"\t|";  
}


cout<<"\nEnter the Target you want to search: ";
cin>>Target;
//start=clock();
for ( i = 0; i < N; i++)
{ 
    if (A[i]==Target)
    {  
         if (flag==1)
    {
         cout<<"First Target Found AT "<<i<<" Index\n";
    }
             
        count+=1;
        temp=i;
        flag=0;
        
    }
       
}
if(count>1)
{
    cout<<"Last Target Found at "<<temp<<" Index";
}
cout<<"Total Targets Found were: "<<count;


if(flag==1)
{
    cout<<"Target Not Found";
}
//end=clock();
//cout<<"\nTime taken to search is "<<double(end-start)/CLOCKS_PER_SEC<<" Seconds"<<endl;
    return 0;
}
