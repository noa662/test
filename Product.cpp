#include "Product.h"

Product::Product() : name("לא ידוע"), price(0), amount(0), kashrut(BADATS) {}

Product::Product(string name, int price, int amount, Kashrut kashrut) :
	name(name), price(price), amount(amount), kashrut(kashrut) {}

Product::Product(const Product& o)
	: name(o.name), price(o.price), amount(o.amount), kashrut(o.kashrut) {}

Product::~Product() {}

int Product::PriceCost() { return price * amount; }

ostream& operator<<(ostream& os, const Product& p)
{
	os << "📦 מוצר: " << p.getName() << endl;
	os << "💰 מחיר: " << p.getPrice() << " ₪" << endl;
	os << "📦 כמות: " << p.getAmount() << endl;
	os << "🛐 כשרות: ";
	switch (p.getKashrut())
	{
	case BADATS: os << "בד\"ץ"; break;
	case RUBIN: os << "רובין"; break;
	case LANDO: os << "לנדא"; break;
	default: os << "לא ידוע"; break;
	}
	os << endl;
	return os;
}

