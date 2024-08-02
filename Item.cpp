#include "Item.h"
#include <iostream>
#include <cmath>
#include <cstring>
#define M 21
using namespace std;

Item::Item(){
	int i;
	itemNo=0;
    for (i=0; i<M; i++){
	itemDesc[i]=' ';
    }
	itemPrice=0;
}

Item::Item(int itemNo1, char itemDesc1[], float itemPrice1){
	itemNo=itemNo1;
	strcpy(itemDesc,itemDesc1);
	itemPrice=itemPrice1;
}

void Item::readData(){
	cout << "Item No: ";
	cin >> itemNo;
	
	cout << "Item Description: ";
	cin >> itemDesc;
    
    
    cout << "Item Price: ";
	cin >> itemPrice;
}

void Item::setData(int itemNo1, char itemDesc1[], float itemPrice1){
	itemNo=itemNo1;
	strcpy(itemDesc,itemDesc1);
	itemPrice=itemPrice1;
}

void Item::printData(){
	/*
	cout << "Item No: " << itemNo << endl;
	cout << "Item Description: " << itemDesc << endl;
	cout << "Item Price: " << itemPrice << endl;
	*/
	cout << itemNo << "|" << itemDesc << "|" << itemPrice << endl;
}

int Item::getItemNo(){
	return itemNo;
}

char* Item::getItemDesc(){
	return itemDesc;
}

float Item::getItemPrice(){
	return itemPrice;
}

