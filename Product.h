#pragma once
#include <iostream>
using namespace std;

enum Kashrut
{
	BADATS,
	RUBIN,
	LANDO
};

class Product
{
private:
	string name;
	int price;
	int amount;
	Kashrut kashrut;

public:
	//בנאים
	Product();
	Product(string name, int price, int amount, Kashrut kashrutLevel);
	Product(const Product& o);
	~Product();
	//פעולות get
	string getName() const { return name; }
	int getPrice() const { return price; }
	int getAmount() const { return amount; }
	Kashrut getKashrut() const { return kashrut; }
	//פעולות set
	void setName(string n) { name = n; } 
	void setPrice(int p) { price = p; }
	void setAmount(int a) { amount = a; }	
	void setKashrut(Kashrut k) { kashrut = k; }
	//פונקציות
	int PriceCost();
	friend ostream& operator<<(ostream& os, const Product& p);
};
