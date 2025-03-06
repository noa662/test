#pragma once
#include <iostream>
#include "Product.h"
using namespace std;

class MishloachManot
{
private:
	string senderName;
	string receivingName;
	string address;
	int toolPrice;
    Product* products;
	int size;
	int capacity;
	static int designPrice;

public:
	//בנאים
	MishloachManot();
	MishloachManot(const MishloachManot& o);
	MishloachManot(string senderName, string receivingName, string address);
	~MishloachManot();
	//פעולות get
	string getSenderName() const { return senderName; }
	string getReceivingName() const { return receivingName; }
	string getAddress() const { return address; }
	int getToolPrice() const { return toolPrice; }
	int getSize() const { return size; }
	int getCapacity() const { return capacity; }
	static int getDesignPrice() { return designPrice; }
	// פעולות set
	void setSenderName(string s) { senderName = s; }
	void setReceivingName(string r) { receivingName = r; }
	void setAddress(string a) { address = a; }
	void setToolPrice(int t) { toolPrice = t; }
	//פונקציות
	void operator+=(const Product& p);
	int MishloachPrice() const;
	Product getProduct(int i) const;
	friend ostream& operator<<(ostream& os, const MishloachManot& m);
	bool IfKasher(Kashrut k);
	bool operator==(const MishloachManot& other) const;
};
