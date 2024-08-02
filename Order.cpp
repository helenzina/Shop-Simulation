#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>

#include "Customer.h"
#include "Item.h"
#include "Order.h"

#define K 11
using namespace std;

Order::Order() : Customer(), Item()
{
	int i;
	orderNo = 0;
	for (i = 0; i < K; i++)
	{
		orderDate[i] = ' ';
	}
	totalAmount = 0;
}

Order::Order(int orderNo1, char orderDate1[], float totalAmount1, int custNo1, char custName1[], char custEmail1[], int itemNo1, char itemDesc1[], float itemPrice1)
	: Customer(custNo1, custName1, custEmail1), Item(itemNo1, itemDesc1, itemPrice1)
{
	orderNo = orderNo1;
	strcpy(orderDate, orderDate1);
	totalAmount = totalAmount1;
}

void Order::readData()
{
	Customer::readData();
	// Item::readData();

	cout << "Order No: ";
	cin >> orderNo;

	cout << "Order Date dd/mm/yyyy: ";
	cin >> orderDate;

	/*
	cout << "Total Purchase Amount: ";
	cin >> totalAmount;
	*/
}

void Order::setData(int orderNo1, char orderDate1[], float totalAmount1, int custNo1, char custName1[], char custEmail1[], int itemNo1, char itemDesc1[], float itemPrice1)
{
	orderNo = orderNo1;
	strcpy(orderDate, orderDate1);
	totalAmount = totalAmount1;
	Customer::setData(custNo1, custName1, custEmail1);
	Item::setData(itemNo1, itemDesc1, itemPrice1);
}

void Order::printData()
{
	Customer::printData();
	cout << "Order No: " << orderNo << endl;
	cout << "Order Date dd/mm/yyyy: " << orderDate << endl;
	// cout << "Total Purchase Amount: " << totalAmount << endl;

	// Item::printData();
}

int Order::getOrderNo()
{
	return orderNo;
}

char *Order::getOrderDate()
{
	return orderDate;
}

float Order::getTotalAmount()
{
	return totalAmount;
}

void Order::buyItem(float price, int qty)
{
	totalAmount = totalAmount + price * qty;
}

int Order::shippingCost()
{
	if (totalAmount > 200)
	{
		return 0;
	}
	else
	{
		// cout << "+Shipping 20" << endl;
		return 20;
	}
}




