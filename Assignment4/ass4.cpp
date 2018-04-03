//============================================================================
// Name        : assgn4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include<stack>
using namespace std;

int equal(string s1, string s2)
{
	if(s1.size()!=s2.size())
		return 0;
	else
	{
		int i;
		for(i=0; i<s1.size(); i++)
		{
			if(s1[i]!=s2[i])
				return 0;
		}
		return 1;
	}
}


class Node
{
	int cost;		//cost to reach it
	string city;
	Node* next;
public:
	Node()
	{
		cost=0;
		city="";
		next=NULL;
	}
	Node(string name, int  cost)
	{
		this->cost=cost;
		this->city=name;
		next=NULL;
	}
	friend class Graph;
};

class Graph
{
	Node *head[20];
	int n;		//number of nodes
public:
	Graph(int n)
	{
		int i;
		this->n=n;
		for(i=0; i<n; i++)
		{
			head[i]= new Node();
		}
	}
	void insert();
	void outDeg();
	void display();
	void inDeg();
	void dfs();
	void del(string city);
	int found(string city);
};

int Graph :: found(string city)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(head[i]->city==city)
			return i;
	}
	return -1;
}

void Graph :: del(string city)
{
	int pos = found(city);
	if(pos ==-1)
	{
		cout<<endl<<"Not Found";
	}
	else
	{
		Node* temp;
		int i=0;
		n--;
		while(i<n) //delete by shift
		{
			head[i]=head[i+1];
			i++;
		}
		while(i<n)
		{
			temp=head[i]->next;
			do
			{
				if(equal((temp->next)->city, city))
				{
					temp->next=temp->next->next;
				}
					temp=temp->next;
			}while(temp->next!=NULL);
			i++;
		}
	}
}

void Graph :: dfs()
{
	int i;
	Node* temp;
	bool visited[n];
	for(i=0; i<n; i++)
		visited[i]=0;
	stack <int> s;
	s.push(0);
	while(!s.empty())
	{
		i=s.top();
		s.pop();
		if(head[i]->next==NULL && (i+1)<n)
		{
			cout<<endl<<(temp->city);
			visited[i]=1;
			s.push(i+1);
			continue;
		}
		else if(head[i]->next==NULL && (i+1)>=n)
		{
			cout<<endl<<(temp->city);
			visited[i]=1;
			break;
		}
		else
		{
			temp= head[i]->next;
			do
			{
				if(!visited[found(temp->city)])
				{
					cout<<endl<<(temp->city);
					visited[found(temp->city)]=1;
					s.push(found(temp->city));
					temp=head[found(temp->city)];
				}
				temp=temp->next;
			}while(temp!=NULL);
		}
	}
}

void Graph :: insert()
{
	Node *p, *temp;
	string s_city, d_city;
	int i, j, con, cost;
	for(i=0; i<n; i++)
	{
		cout<<endl<<"Enter name of city #"<<(i+1);
		cin.ignore();
		cin>>s_city;
		(*(head+i))->city=s_city;
		temp= *(head+i);
		cout<<endl<<"Enter the number of connected cities";
		cin>>con;
		for(j=0; j<con; j++)
		{
			cout<<endl<<"Enter name of connected city#"<<(j+1)<<" ";
			cin>>d_city;
			cout<<endl<<"Enter the distance ";
			cin>>cost;
			p= new Node(d_city, cost);
			temp->next= p;
			temp=temp->next;
		}
	}
}

void Graph :: display()
{
	int i;
	Node* temp_s, *temp_d;
	for(i=0; i<n; i++)
	{
		if(head[i]->next==NULL)
			continue;
		temp_s=head[i];
		cout<<endl<<endl<<temp_s->city<<" is connected to: ";
		temp_d=temp_s->next;
		do
		{
			cout<<endl<<temp_d->city<<" with distance: "<<temp_d->cost;
			temp_d=temp_d->next;
		}while(temp_d!=NULL);
	}
}

void Graph :: outDeg()
{
	int i, count;
	Node *temp;
	for(i=0; i<n; i++)
	{
		temp=head[i]->next;
		count=0;
		do
		{
			temp=temp->next;
			count++;
		}while(temp->next!=NULL);
		cout<<endl<<head[i]->city<<" has outdegree"<<count;
	}
}

void Graph :: inDeg()
{
	int i, j;
	int count;
	Node *temp;
	for(i=0; i<n; i++)
	{
		count=0;
		for(j=0; j<n; j++)
		{
			if(i==j)
				continue;
			temp=head[j];
			do
			{
				if(equal(temp->city,head[i]->city))
					count++;

				temp=temp->next;
			}while(temp!=NULL);
		}
		cout<<endl<<head[i]->city<<" has indegree"<<count;
	}
}


int main() {
	int n, choice;
	string city;
	cout<<endl<<"Enter number of cities";
	cin>>n;
	Graph G(n);
	cout<<endl<<"Enter the data:";
	G.insert();
	do
	{
		cout<<endl<<"Enter choice: "<<endl<<"1)Display 2)Display outdegree 3)Display indegree 4)DFS 5)Delete Node 6)Exit";
		cin>>choice;
		switch(choice)
		{
		case 1:
			G.display();
			break;
		case 2:
			G.outDeg();
			break;
		case 3:
			G.inDeg();
			break;
		case 4:
			G.dfs();
			break;
		case 5:
			cout<<endl<<"Enter city to be deleted";
			cin>>city;
			G.del(city);
		}
	}while(choice!=6);
	return 0;
}
