//Ashlyn Hanks
//August 28, 2020
//CSC 2710-01
//Create an algorithm that will  perform an exchange sort

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Initialie struct for data
struct Person
{
	string first;
	string last;
	int age;
};

//
void Load(struct Person data[])
{
//Open file
	ifstream inFile;
	inFile.open("Data.txt");


	int i;
	for (i=0; i<100000; i++)
	{
		inFile >> data[i].first >> data[i].last >> data[i].age;
	}
}

void Exchangesort(struct Person data[])
{
	int i, j;
	Person t;
	for(i=0; i< 100000; i++)
	{
	   if (data[i].first == "")
	   {
	      break;
	   }
		for (j=0; j< 100000; j++)
		{
			if (data[i].last.front() < data[j].last.front())
			{
				t=data[i];
				data[i]=data[j];
				data[j]=t;
			}
		}
	}
}

void Print (struct Person data[])
{
	int i=0;
	while (data[i].first != "")
	{
		cout << data[i].last << "," << data[i].first << "-" << data[i].age << endl;
		i++;
	}
}

int main()
{
	Person data[100000];
	Load(data);
	Exchangesort(data);
	Print(data);	
}

