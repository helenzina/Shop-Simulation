#include "Customer.h"
#include <iostream>
#include <cmath>
#include <cstring>
#define M 21
using namespace std;

Customer::Customer(){
	int i;
	custNo=0;
    for (i=0; i<M; i++){
	custName[i]=' ';
	custEmail[i]=' ';	
	}
}

Customer::Customer(int custNo1, char custName1[], char custEmail1[]){
	custNo=custNo1;
	strcpy(custName,custName1);
	strcpy(custEmail,custEmail1);
}

void Customer::readData(){
	cout << "Customer No: ";
	cin >> custNo;
	
	cout << "Customer Name: ";
	cin >> custName;
	
	cout << "Customer Email: ";
	cin >> custEmail;
}

void Customer::setData(int custNo1, char custName1[], char custEmail1[]){
	custNo=custNo1;
	strcpy(custName,custName1);
	strcpy(custEmail,custEmail1);
}

void Customer::printData(){
	cout << "Customer No: " << custNo << endl;
	cout << "Customer Name: " << custName <<endl;
	cout << "Customer Email: "<< custEmail << endl;
}

int Customer::getCustNo(){
	return custNo;
}

char* Customer::getCustName(){
	return custName;
}

char* Customer::getCustEmail(){
	return custEmail;
}
