#include "MishloachManot.h"

int MishloachManot::designPrice = 15;

MishloachManot::MishloachManot() 
	: senderName(""), receivingName(""), address(""), toolPrice(15), products(nullptr), size(0), capacity(2) {}

MishloachManot::MishloachManot(const MishloachManot& o):
	senderName(o.senderName), receivingName(o.receivingName), address(o.address), toolPrice(o.toolPrice), size(o.size), capacity(o.capacity)
{
	products = new Product[capacity];
	for (int i = 0; i < size; i++)
	{
		products[i] = o.products[i];
	}
}

MishloachManot::MishloachManot(string senderName, std::string receivingName, string address)
	: senderName(senderName), receivingName(receivingName), address(address), toolPrice(15), products(nullptr), size(0), capacity(2)
{
	products = new Product[capacity];
}

MishloachManot::~MishloachManot()
{
	delete[] products;
}

void MishloachManot::operator+=(const Product& p)
{
	if (size >= capacity)
	{
		capacity *= 2;
		Product* newProducts = new Product[capacity];
		for (int i = 0; i < size; i++)
			newProducts[i] = products[i];
		delete[]products;
		products = newProducts;
		products[size++] = p;
	}
}

int MishloachManot::MishloachPrice() const
{
	int sum = toolPrice + getDesignPrice();
	for (int i = 0; i < size; i++)
		sum += products[i].PriceCost();
	return sum;
}

Product MishloachManot::getProduct(int i) const
{
	if (i >= 0 && i < size)
		return products[i];
	return Product("", 0, 0, BADATS);
}

ostream& operator<<(ostream& os, const MishloachManot& m)
{
	os << "🎁 משלוח מנות" << endl;
	os << "📤 שולח: " << m.getSenderName() << endl;
	os << "📥 מקבל: " << m.getReceivingName() << endl;
	os << "📍 כתובת: " << m.getAddress() << endl;
	os << "🛍️ מחיר הכלי: " << m.getToolPrice() << " ₪" << endl;
	os << "📦 מוצרים במשלוח:" << endl;
	for (int i = 0; i < m.getSize(); i++)
		os << "  " << (i + 1) << ". " << m.getProduct(i) << endl;
	os << "---------------------------------" << endl;
	os << "💰 מחיר כולל: " << m.MishloachPrice() << " ₪" << endl;
	return os;
}

bool MishloachManot::IfKasher(Kashrut k)
{
	for (int i = 0; i < size; i++)
		if (products[i].getKashrut() != k)
			return false;
	return true;
}

bool MishloachManot::operator==(const MishloachManot& other) const
{
	return MishloachPrice() == other.MishloachPrice();
}