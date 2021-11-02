//Ashlyn Hanks 
//CSC 2710
//A program using Floyd's Algorithm

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int infinity=999999999;

int main()
{
    string file; 
    cout << "Please enter the desired file name:" << endl;
    cin >> file;

    int a;
    int b;
    ifstream input;
    input.open(file);
    input >> a;
    input >> b;

    int imat[a][a];
    int X[a][a];

    for(int i=0; i<a; i++)
   
	for(int j=0; j<a; j++)
	    if(i!=j)
		imat[i][j] = infinity;
	    else
		imat[i][j] = 0;
    

    int c, d, e;
    for(int i=0; i<b; i++)
    
	input >> c;
	input >> d;
	input >> e;
	imat[c-1][d-1] = e;
    

    input.close();

    cout << endl;
    cout << "Initial Array Matrix:" << endl;
    for (int i=0; i<a; i++)
	for (int j=0; j<a; j++)
	    X[i][j]=imat[i][j];

    for(int i=0; i<a; i++)
    {
	for(int j=0; j<a; j++)
	{
	    if(i!=j)
	    {
		if(X[i][j] > 0 && X[i][j] != infinity)
		    cout << X[i][j] << " ";
		else 
		    cout << "INF ";
	    }
	    else 
		cout << X[i][j] << " ";
	}
    }

    int dist[a][a];
    
    for(int i=0; i<a; i++)
	for(int j=0; j<a; j++)
	    dist[i][j] = X[i][j];
    for(int w=0; w<a; w++)
    {
	for(int i=0; i<a; i++)
	{
	    for(int j=0; j<a; j++)
	    {
		if(dist[i][w] + dist[w][j] < dist[i][j])
		    dist[i][j] = dist[i][w] + dist[w][j];
	    }
	}
    }

    cout << endl;
    cout << "Final Array Matrix:" << endl;
    for(int i=0; i<a; i++)
	for(int j=0; j<a; j++)
	    X[i][j] = dist[i][j];

    for(int i=0; i<a; i++)
    {
	for(int j=0; j<a; j++)
	{
	    if( i!= j)
	    {
		if(X[i][j]>0 && X[i][j] != infinity)
		    cout << X[i][j] << " ";
		else
		    cout << "INF ";
	    }
	    else
		cout << X[i][j] << " ";
	}
    }

    return 0;
}
