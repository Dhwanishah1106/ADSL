#include <iostream>
using namespace std;

class heap{
int* max;
int* min;
int n;

public:
	heap(int d){
		n=d;
		max=new int[n+1];
		max[0]=0;
		min=new int[n+1];
		min[0]=0;
	}
	void getdata(int);
	void createmin(int);
	void createmax(int);
	void print();
};

void heap::print(){
	cout<<"\nMINIMUM MARKS ARE: "<<min[1]<<"\nMAXIMUM MARKS ARE: "<<max[1]<<"\n";
}

void heap::createmin(int i){
	int temp;

	while(i>1 && min[i]<min[i/2])
			{
					temp=min[i];
					min[i]=min[i/2];
					min[i/2]=temp;
				i=i/2;
			}
}
void heap::createmax(int i){
	int temp;

	while(i>1 && max[i]>max[i/2])
			{
					temp=max[i];
					max[i]=max[i/2];
					max[i/2]=temp;
				i=i/2;
			}

}



void heap::getdata(int x){
	min[++min[0]]=x;
	max[++max[0]]=x;
	createmax(max[0]);
	createmin(min[0]);
}


int main() {
	int n,x;
cout<<"\nEnter the Number of students";
cin>>n;
heap obj(n);
for(int i=0;i<n;i++){
	cout<<"\n Enter Marks: ";
	cin>>x;
	while(x<0){
	cout<<"Please enter positive value: ";
	cin>>x;
	}
	obj.getdata(x);
	}
obj.print();

	return 0;
}
