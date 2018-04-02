#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

struct customer
{
	char name[30];
	unsigned long long int id;
	float balance;
	int dob[3];
};

class bankfiles
{
	//private:
	public:
	 customer get(unsigned long long int cid)
	{
		struct customer cust;
		FILE *fp;
		fp = fopen("custbase.txt","r");
		while(!feof(fp))
		{
			fscanf(fp,"%s %llu %f %d/%d/%d \n",cust.name,cust.id,cust.balance,cust.dob[0],cust.dob[1],cust.dob[2]);
			{
				if(cust.id == cid)
					return cust;	
			}
		}
	}	
	 void put()
	{
		struct customer cust;
		FILE *fp;
		fp = fopen("custbase.txt","a");
		cout<<"Enter name : ";
		cin>>cust.name;
		srand(time(NULL));
		cust.id=createid();//cout<<cust.id;
		cout<<"Enter DOB : dd/mm/yyyy \n" ;
		scanf("%d/%d/%d",&cust.dob[0],&cust.dob[1],&cust.dob[2]);
		cout<<"Enter initials : ";
		cin>>cust.balance;
		cout<<"\t The assigned ID is : "<<cust.id<<endl;
		fprintf(fp,"%s %llu %f %d/%d/%d \n",cust.name,cust.id,cust.balance,cust.dob[0],cust.dob[1],cust.dob[2]);
	}
	unsigned long long int createid()
	{
	string s,a,final;unsigned long long int id=0;
	string init = "1608";
	s="0123456789";
	int n = s.length();
	for(int i=0;i<4;i++)
		final.push_back(s[rand() % n]);
	a = init + final;
	stringstream idcreate(a);
	idcreate>>id;
	return id;
	}
};


