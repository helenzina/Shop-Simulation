#include <iostream>
#include <fstream>
#include <iomanip>

#include "Item.h"
#include "Customer.h"
#include "Order.h"

#define Z 100
using namespace std;

void processInfo(Order orderID, ofstream &outfile);

void processOrder(Order orderID, Item itemArr[], ifstream &infile, ofstream &outfile);

int fileToArr(ifstream &infile, Item itemArr[]);
// diabazei plhrofories ap to items.txt kai tis paei se ena pinaka proiontwn/antikeimenwn (me Item::setData()), epistrefontas to count twn proiontwn poy mphkane.

int itemMenu(Item itemArr[], int n);
// dexetai ton pinaka kai to count (int n) apo th fileToArr kai ta emfanizei se mia lista. meta zhta enan kwdiko proiontos gia agora apo th lista kai ton epistrefei.

int searchItem(Item itemArr[], int n, int searchCode);
// dexetai ton pinaka kai to count (int n) apo th fileToArr kai enan kwdiko proiontos apo thn itemMenu() kai elegxei an o kwdikos yparxei(epistrefei thesh pinaka) h oxi(epistrefei -1).

void processFile(Item itemArr[], int pos, int qty, ofstream &outfile);

void processShipping(Order orderID, ofstream &outfile);

int main()
{

	Item itemArr[Z]; // gia mexri 100 to poly proionta
	Order orderID;

	ifstream infile("ITEMS.TXT");	// me plhrofories gia oxi parapanw apo 10 proionta
	ofstream outfile("ORDERS.TXT"); // katagrafh agorwn proiontwn apo pelates

	processOrder(orderID, itemArr, infile, outfile);

	return 0;
}

void processInfo(Order orderID, ofstream &outfile)
{
	orderID.readData();

	outfile << "Customer No: " << orderID.getCustNo() << endl;
	outfile << "Customer Name: " << orderID.getCustName() << endl;
	outfile << "Customer Email: " << orderID.getCustEmail() << endl;
	outfile << "Order No: " << orderID.getOrderNo() << endl;
	outfile << "Order Date dd/mm/yyyy: " << orderID.getOrderDate() << endl;
	outfile << endl;
	outfile << "No ";
	outfile << "Description       ";
	outfile << "Quantity  ";
	outfile << " Price  ";
	outfile << "  Value ";
	outfile << endl;
	outfile << "======= ";
	outfile << "=============== ";
	outfile << "======== ";
	outfile << " ====== ";
	outfile << " ====== ";
	outfile << endl;

	cout << endl;
}

void processOrder(Order orderID, Item itemArr[], ifstream &infile, ofstream &outfile)
{
	int n, searchCode, pos, qty;

	if (!infile)
		cout << "Cannot find input file!" << endl;
	else
	{
		// cout << "File found." << endl;
		processInfo(orderID, outfile);
		n = fileToArr(infile, itemArr);

		searchCode = itemMenu(itemArr, n);

		while (searchCode != 0)
		{
			pos = searchItem(itemArr, n, searchCode);

			if (pos > -1)
			{
				cout << "Quantity: ";
				cin >> qty;
				orderID.buyItem(itemArr[pos].getItemPrice(), qty);
				processFile(itemArr, pos, qty, outfile);
			}
			else
			{
				cout << "The purchase wasn't made, try again." << endl;
			}

			searchCode = itemMenu(itemArr, n);
		}
	}

	if (searchCode == 0)
	{
		cout << "Order finished. " << endl;
		infile.close();
	}

	processShipping(orderID, outfile);
}

int fileToArr(ifstream &infile, Item itemArr[])
{
	int itemNo, i, n;
	char itemDesc[M];
	float itemPrice;

	n = 0;
	infile >> itemNo;
	while (!infile.eof())
	{
		infile.get(itemDesc, M - 1);
		infile >> itemPrice;
		itemArr[n].setData(itemNo, itemDesc, itemPrice);
		infile >> itemNo;
		n++;
	}

	return n;
}

int itemMenu(Item itemArr[], int n)
{
	int i, searchCode;
	cout << "ITEMS LIST" << endl
		 << "===========================" << endl;
	for (i = 0; i < n; i++)
	{
		itemArr[i].printData();
	}
	cout << "Give item No to buy (0 to finish order): ";
	cin >> searchCode;
	cout << endl;
	return searchCode;
}

int searchItem(Item itemArr[], int n, int searchCode)
{
	int i, pos;
	bool found = false;
	i = 0;
	found = false;

	while (i < n && found == false)
	{

		if (itemArr[i].getItemNo() == searchCode)
		{
			found = true;
			pos = i;
		}
		else
			i++;
	}

	if (found == true)
	{
		itemArr[pos].printData();
	}
	else
	{
		cout << "The item No " << searchCode << " doesn't exist in the items list. " << endl;
		pos = -1;
	}

	return pos;
}

void processFile(Item itemArr[], int pos, int qty, ofstream &outfile)
{

	outfile << "  " << itemArr[pos].getItemNo()
			<< "  " << itemArr[pos].getItemDesc()
			<< setw(3) << qty
			<< setw(11) << itemArr[pos].getItemPrice()
			<< setw(8) << qty * itemArr[pos].getItemPrice()
			<< endl;
}

void processShipping(Order orderID, ofstream &outfile)
{
	outfile << endl;
	outfile << setw(42) << "Total Purchase Amount: ";
	outfile << orderID.getTotalAmount();
	outfile << endl;
	outfile << setw(42) << "Shipping Cost: ";
	outfile << orderID.shippingCost();
	outfile.close();
}
