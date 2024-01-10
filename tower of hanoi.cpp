#include <stdio.h>
#include<iostream>
using namespace std;
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if ( n<= 0)
	{
		return;
	}
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	cout<< "Move disk " << n << " from rod " << from_rod <<" to rod " << to_rod << endl;
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    }
int main()
{
	int n;
	cout<<"Enter the number of disk: \n";
	cin>>n;
	if(n<0)
	{
		cout<<"Please enter the positive number.\n";
	} 			
	else if (n==0)
	{
		cout<<"Enter the number other than zero.";
	}								//number of shifts is (2^n)-1
	towerOfHanoi(n, 'A', 'C', 'B');
	return 0;
}
